#pragma once
#include "ElfHelpers.h"
#include <libos/Error.h>
#include <libos/FileIO.h>
namespace libos::extensions::elfloader::helpers
{
losResult readAllElf64SecHdr(std::vector<Elf64SectionHeader> &headers, const char ptr[], const size_t soffset,
                             const size_t snumber) noexcept
{
    Elf64_Off offset = soffset;
    for (Elf64_Off index = 0; index != snumber; index++)
    {
        Elf64SectionHeader sheader{};
        try
        {
            memcpy(&sheader, &ptr[offset], sizeof(Elf64SectionHeader));
        }
        catch (...)
        {
            return LOS_ERROR_MALFORMED_DATA;
        }
        offset += sizeof(Elf64SectionHeader);
        headers.emplace_back(sheader);
    }
    return LOS_SUCCESS;
}

losResult readAllElf64PrgHdr(std::vector<Elf64ProgramHeader> &headers, const char ptr[], const size_t poffset,
                                    const size_t pnumber) noexcept
{
    Elf64_Off offset = poffset;
    for (Elf64_Off index = 0; index != pnumber; index++)
    {
        Elf64ProgramHeader pheader{};
        try
        {
            memcpy(&pheader, &ptr[offset], sizeof(Elf64ProgramHeader));
        }
        catch (...)
        {
            return LOS_ERROR_MALFORMED_DATA;
        }
        offset += sizeof(Elf64ProgramHeader);
        headers.emplace_back(pheader);
    }
    return LOS_SUCCESS;
}

losResult readElf64Header(Elf64Header &header, const char *file_data, const size_t &file_size) noexcept
{
    try
    {
        const char magic[4] = {0x7F, 'E', 'L', 'F'};
        if (strncmp((const char *)((const Elf64Header *)file_data)->e_ident.ei_magic, magic, 4) != 0)
            return LOS_ERROR_MALFORMED_DATA;
        if (((const Elf64Header *)file_data)->e_ident.ei_class != Elf64Class::_64)
        {
            losPrintError(
                "[LIBOS::ELF_LOADER]: tried to load a none 64bit elf file we only ever will support 64bit elfs");
            return LOS_ERROR_COULD_NOT_INIT;
        }
        if (((const Elf64Header *)file_data)->e_machine != Elf64Machine::X86_64)
        {
            losPrintError("[LIBOS::ELF_LOADER]: tried to load a none x86_64 elf file we only support x86_64 right now");
            return LOS_ERROR_COULD_NOT_INIT;
        }
        if (((const Elf64Header *)file_data)->e_version == 0)
        {
            losPrintError("[LIBOS::ELF_LOADER]: tried to load a elf file with bad elf version");
            return LOS_ERROR_COULD_NOT_INIT;
        }
        if (((const Elf64Header *)file_data)->e_ident.ei_data_encoding != 1)
        {
            losPrintError("[LIBOS::ELF_LOADER]: tried to load a elf file has big enitan or corupted elf data encoding "
                          "this is a no no");
            return LOS_ERROR_COULD_NOT_INIT;
        }
        if (((const Elf64Header *)file_data)->e_ident.ei_abi_version != 0)
        {
            losPrintError("[LIBOS::ELF_LOADER]: tried to load a elf file with bad abi elf version");
            return LOS_ERROR_COULD_NOT_INIT;
        }
        if (((const Elf64Header *)file_data)->e_type != Elf64Type::EXEC &&
            ((const Elf64Header *)file_data)->e_type != Elf64Type::DYN &&
            ((const Elf64Header *)file_data)->e_type != Elf64Type::REL &&
            ((const Elf64Header *)file_data)->e_type != Elf64Type::CORE)
        {
            losPrintError("[LIBOS::ELF_LOADER]: tried to load a elf file with an none supported type loader expected "
                          "REL, EXEC, DYN or CORE");
            return LOS_ERROR_COULD_NOT_INIT;
        }
        if (((const Elf64Header *)file_data)->e_phoff > file_size ||
            ((const Elf64Header *)file_data)->e_shoff > file_size)
        {
            losPrintError("[LIBOS::ELF_LOADER]: AHHHHH! corupted elf header pointer files");
            return LOS_ERROR_COULD_NOT_INIT;
        }
        // TODO/FIXME: need to add all safety checks for the spec
        memcpy(&header, file_data, sizeof(Elf64Header));
    }
    catch (...)
    {
        return LOS_ERROR_MALFORMED_DATA;
    }
    return LOS_SUCCESS;
}

losResult elfReadFile(const char *path, const size_t path_len, void **read_str, size_t *read_str_size) noexcept
{
    losFileHandle handle;
    losFileOpenInfo file{};
    file.fileBits = LOS_FILE_BIT_READ;
    file.path = path;
    file.path_size = path_len;
    ELF_CHECK(losOpenFile(&handle, file));
    ELF_CHECK(losReadFile(handle, read_str, read_str_size));
    ELF_CHECK(losCloseFile(handle));
    return LOS_SUCCESS;
}
} // namespace libos::extensions::elfloader::helpers