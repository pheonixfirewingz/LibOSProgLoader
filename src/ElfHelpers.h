#pragma once
#include "Elf.h"
#include <libos/DataType.h>
#include <vector>
namespace libos::extensions::elfloader::helpers
{
losResult elfReadFile(const char *path, const size_t path_len, void **read_str, size_t *read_str_size) noexcept;
losResult readElf64Header(Elf64Header &header, const char *file_data, const size_t &file_size) noexcept;
losResult readAllElf64PrgHdr(std::vector<Elf64ProgramHeader> &headers, const char ptr[], const size_t poffset,
                             const size_t pnumber) noexcept;
losResult readAllElf64SecHdr(std::vector<Elf64SectionHeader> &headers, const char ptr[], const size_t soffset,
                             const size_t snumber) noexcept;

  #define ELF_CHECK(x) if (losResult res = x;res != LOS_SUCCESS) return res
} // namespace libos::extensions::elfloader::helpers