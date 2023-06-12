#include "ElfLoader.h"
#include "Elf.h"
#include "ElfHelpers.h"
#ifdef WITH_DEBUG
#    include "PrintElf.h"
#endif
#include <libos/Error.h>
#include <map>
#include <memory>

using namespace libos::extensions::elfloader;
using namespace libos::extensions::elfloader::helpers;
#ifdef WITH_DEBUG
using namespace libos::extensions::elfloader::debug;
#endif

losResult loseExec(_in_ const loseExecInfo exec_info)
{
    std::unique_ptr<char> read_str;
    size_t read_str_size = 0;
    ELF_CHECK(elfReadFile(exec_info.path, exec_info.path_size, std::out_ptr(read_str), &read_str_size));
    std::vector<Elf64ProgramHeader> program_headers;
    std::vector<Elf64SectionHeader> section_headers;
#ifdef WITH_DEBUG
    std::map<Elf64_Off, std::string> section_headers_names;
#endif
    Elf64Header header{};
    ELF_CHECK(readElf64Header(header, read_str.get(), read_str_size));
    program_headers.reserve(header.e_phnum);
    section_headers.reserve(header.e_shnum);
    ELF_CHECK(readAllElf64PrgHdr(program_headers, read_str.get(), header.e_phoff, header.e_phnum));
    ELF_CHECK(readAllElf64SecHdr(section_headers, read_str.get(), header.e_shoff, header.e_shnum));

#ifdef WITH_DEBUG
    for (Elf64_Off index = 0; index <= section_headers[header.e_shstrndx].sh_size;)
    {
        std::string str(read_str.get() + (section_headers[header.e_shstrndx].sh_offset + index));
        section_headers_names.emplace(index, str);
        index += str.length() + 1;
    }
#endif
    section_headers.erase(section_headers.begin() + header.e_shstrndx);

    for (auto &ph : program_headers)
        printElf64ProgramHeader(ph);

    for (auto &sh : section_headers)
        printElf64SectionHeader(sh, section_headers_names);

    return LOS_SUCCESS;
}