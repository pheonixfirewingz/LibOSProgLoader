#include "ElfLoader.h"
#include "Elf.h"
#include <libos/FileIO.h>
#include <libos/Error.h>
#include <memory>

using namespace libos::extensions::elfloader;

static inline losResult readElf64SectionHeader(Elf64SectionHeader& header,const char file_data_access_point[], const size_t offset) noexcept
{
	try
	{
		memcpy(&header, &file_data_access_point[offset], sizeof(Elf64SectionHeader));
	}
	catch(...)
	{
		return LOS_ERROR_MALFORMED_DATA;
	}
	return LOS_SUCCESS;
}

static inline losResult readElf64Header(Elf64Header& header, const char* file_data) noexcept
{
	try
	{
		const char magic[4] = { 0x7F, 'E', 'L','F' };
		if (strncmp((const char*)((const Elf64Header*)file_data)->e_ident.ei_magic, magic, 4) != 0)
			return LOS_ERROR_MALFORMED_DATA;
		if (((const Elf64Header*)file_data)->e_ident.ei_class != Elf64Class::_64)
		{
			losPrintError("[LIBOS::ELF_LOADER]: tried to load a none 64bit elf file we only ever will support 64bit elfs");
			return LOS_ERROR_COULD_NOT_INIT;
		}
		if (((const Elf64Header*)file_data)->e_machine != Elf64Machine::X86_64)
		{
			losPrintError("[LIBOS::ELF_LOADER]: tried to load a none x86_64 elf file we only support x86_64 right now");
			return LOS_ERROR_COULD_NOT_INIT;
		}
		memcpy(&header, file_data, sizeof(Elf64Header));
	}
	catch (...)
	{
		return LOS_ERROR_MALFORMED_DATA;
	}
	return LOS_SUCCESS;
}

losResult loseExec(_in_ const loseExecInfo exec_info)
{
	std::unique_ptr<char> read_str;
	size_t read_str_size = 0;
	{

		losFileHandle handle;
		losFileOpenInfo file{};
		file.fileBits = LOS_FILE_BIT_READ;
		file.path = exec_info.path;
		file.path_size = exec_info.path_size;
		if (losResult res = losOpenFile(&handle, file); res != LOS_SUCCESS)
			return res;
		if (losResult res = losReadFile(handle, std::out_ptr(read_str), &read_str_size); res != LOS_SUCCESS)
			return res;
		if (losResult res = losCloseFile(handle); res != LOS_SUCCESS)
			return res;
	}
	Elf64Header header{};
	if (losResult res = readElf64Header(header,read_str.get()); res != LOS_SUCCESS)
		return res;
	if (header.e_shoff == 0)
	{
		losPrintError("[LIBOS::ELF_LOADER]: elf file has no data sections");
		return LOS_ERROR_MALFORMED_DATA;
	}
	Elf64SectionHeader sheader{};
	{
		if (losResult res = readElf64SectionHeader(sheader, read_str.get(), header.e_shoff); res != LOS_SUCCESS)
			return res;
	}
	return LOS_SUCCESS;
}