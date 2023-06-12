#pragma once
#include "Elf.h"
#include <iomanip>
#include <iostream>
#include <map>
#include <stdio.h>
// temp debug
namespace libos::extensions::elfloader::debug
{
inline std::ostream &operator<<(std::ostream &os, Elf64Type type)
{
    switch (type)
    {
    case Elf64Type::NONE:
        os << "NONE";
        break;
    case Elf64Type::REL:
        os << "REL";
        break;
    case Elf64Type::EXEC:
        os << "EXEC";
        break;
    case Elf64Type::DYN:
        os << "DYN";
        break;
    case Elf64Type::CORE:
        os << "CORE";
        break;
    case Elf64Type::LOOS:
        os << "LOOS";
        break;
    case Elf64Type::HIOS:
        os << "HIOS";
        break;
    case Elf64Type::LOPROC:
        os << "LOPROC";
        break;
    case Elf64Type::HIPROC:
        os << "HIPROC";
        break;
    default:
        os << "Unknown";
        break;
    }
    return os;
}

inline std::ostream &operator<<(std::ostream &os, Elf64Machine machine)
{
    switch (machine)
    {
    case Elf64Machine::NONE:
        os << "NONE";
        break;
    case Elf64Machine::M32:
        os << "M32";
        break;
    case Elf64Machine::SPARC:
        os << "SPARC";
        break;
    case Elf64Machine::I386:
        os << "I386";
        break;
    case Elf64Machine::K68:
        os << "K68";
        break;
    case Elf64Machine::K88:
        os << "K88";
        break;
    case Elf64Machine::I860:
        os << "I860";
        break;
    case Elf64Machine::MIPS:
        os << "MIPS";
        break;
    case Elf64Machine::S370:
        os << "S370";
        break;
    case Elf64Machine::MIPS_RS3_LE:
        os << "MIPS_RS3_LE";
        break;
    case Elf64Machine::PARISC:
        os << "PARISC";
        break;
    case Elf64Machine::VPP500:
        os << "VPP500";
        break;
    case Elf64Machine::SPARC32PLUS:
        os << "SPARC32PLUS";
        break;
    case Elf64Machine::I960:
        os << "I960";
        break;
    case Elf64Machine::PPC:
        os << "PPC";
        break;
    case Elf64Machine::PPC64:
        os << "PPC64";
        break;
    case Elf64Machine::S390:
        os << "S390";
        break;
    case Elf64Machine::V800:
        os << "V800";
        break;
    case Elf64Machine::FR20:
        os << "FR20";
        break;
    case Elf64Machine::RH32:
        os << "RH32";
        break;
    case Elf64Machine::RCE:
        os << "RCE";
        break;
    case Elf64Machine::ARM:
        os << "ARM";
        break;
    case Elf64Machine::ALPHA:
        os << "ALPHA";
        break;
    case Elf64Machine::SH:
        os << "SH";
        break;
    case Elf64Machine::SPARCV9:
        os << "SPARCV9";
        break;
    case Elf64Machine::TRICORE:
        os << "TRICORE";
        break;
    case Elf64Machine::ARC:
        os << "ARC";
        break;
    case Elf64Machine::H8_300:
        os << "H8_300";
        break;
    case Elf64Machine::H8_300H:
        os << "H8_300H";
        break;
    case Elf64Machine::H8S:
        os << "H8S";
        break;
    case Elf64Machine::H8_500:
        os << "H8_500";
        break;
    case Elf64Machine::IA_64:
        os << "IA_64";
        break;
    case Elf64Machine::MIPS_X:
        os << "MIPS_X";
        break;
    case Elf64Machine::COLDFIRE:
        os << "COLDFIRE";
        break;
    case Elf64Machine::_68HC12:
        os << "_68HC12";
        break;
    case Elf64Machine::MMA:
        os << "MMA";
        break;
    case Elf64Machine::PCP:
        os << "PCP";
        break;
    case Elf64Machine::NCPU:
        os << "NCPU";
        break;
    case Elf64Machine::NDR1:
        os << "NDR1";
        break;
    case Elf64Machine::STARCORE:
        os << "STARCORE";
        break;
    case Elf64Machine::ME16:
        os << "ME16";
        break;
    case Elf64Machine::ST100:
        os << "ST100";
        break;
    case Elf64Machine::TINYJ:
        os << "TINYJ";
        break;
    case Elf64Machine::X86_64:
        os << "X86_64";
        break;
    case Elf64Machine::PDSP:
        os << "PDSP";
        break;
    case Elf64Machine::PDP10:
        os << "PDP10";
        break;
    case Elf64Machine::PDP11:
        os << "PDP11";
        break;
    case Elf64Machine::FX66:
        os << "FX66";
        break;
    case Elf64Machine::ST9PLUS:
        os << "ST9PLUS";
        break;
    case Elf64Machine::ST7:
        os << "ST7";
        break;
    case Elf64Machine::_68HC16:
        os << "_68HC16";
        break;
    case Elf64Machine::_68HC11:
        os << "_68HC11";
        break;
    case Elf64Machine::_68HC08:
        os << "_68HC08";
        break;
    case Elf64Machine::_68HC05:
        os << "_68HC05";
        break;
    case Elf64Machine::SVX:
        os << "SVX";
        break;
    case Elf64Machine::ST19:
        os << "ST19";
        break;
    case Elf64Machine::VAX:
        os << "VAX";
        break;
    case Elf64Machine::CRIS:
        os << "CRIS";
        break;
    case Elf64Machine::JAVELIN:
        os << "JAVELIN";
        break;
    case Elf64Machine::FIREPATH:
        os << "FIREPATH";
        break;
    case Elf64Machine::ZSP:
        os << "ZSP";
        break;
    case Elf64Machine::MMIX:
        os << "MMIX";
        break;
    case Elf64Machine::HUANY:
        os << "HUANY";
        break;
    case Elf64Machine::PRISM:
        os << "PRISM";
        break;
    case Elf64Machine::AVR:
        os << "AVR";
        break;
    case Elf64Machine::FR30:
        os << "FR30";
        break;
    case Elf64Machine::D10V:
        os << "D10V";
        break;
    case Elf64Machine::D30V:
        os << "D30V";
        break;
    case Elf64Machine::V850:
        os << "V850";
        break;
    case Elf64Machine::M32R:
        os << "M32R";
        break;
    case Elf64Machine::MN10300:
        os << "MN10300";
        break;
    case Elf64Machine::MN10200:
        os << "MN10200";
        break;
    case Elf64Machine::PJ:
        os << "PJ";
        break;
    case Elf64Machine::OPENRISC:
        os << "OPENRISC";
        break;
    case Elf64Machine::ARC_A5:
        os << "ARC_A5";
        break;
    case Elf64Machine::XTENSA:
        os << "XTENSA";
        break;
    case Elf64Machine::VIDEOCORE:
        os << "VIDEOCORE";
        break;
    case Elf64Machine::TMM_GPP:
        os << "TMM_GPP";
        break;
    case Elf64Machine::NS32K:
        os << "NS32K";
        break;
    case Elf64Machine::TPC:
        os << "TPC";
        break;
    case Elf64Machine::SNP1K:
        os << "SNP1K";
        break;
    case Elf64Machine::ST200:
        os << "ST200";
        break;
    default:
        os << "Unknown";
        break;
    }
    return os;
}

inline std::ostream &operator<<(std::ostream &os, Elf64Class _class_)
{
    switch (_class_)
    {
    case Elf64Class::NONE:
        os << "NONE";
        break;
    case Elf64Class::_32:
        os << "32-bit";
        break;
    case Elf64Class::_64:
        os << "64-bit";
        break;
    default:
        os << "Unknown";
        break;
    }
    return os;
}

inline std::ostream &operator<<(std::ostream &os, Elf64OSABI abi)
{
    switch (abi)
    {
    case Elf64OSABI::NONE:
        os << "NONE";
        break;
    case Elf64OSABI::HPUX:
        os << "HPUX";
        break;
    case Elf64OSABI::NETBSD:
        os << "NETBSD";
        break;
    case Elf64OSABI::LINUX:
        os << "LINUX";
        break;
    case Elf64OSABI::SOLARIS:
        os << "SOLARIS";
        break;
    case Elf64OSABI::AIX:
        os << "AIX";
        break;
    case Elf64OSABI::IRIX:
        os << "IRIX";
        break;
    case Elf64OSABI::FREEBSD:
        os << "FREEBSD";
        break;
    case Elf64OSABI::TRU64:
        os << "TRU64";
        break;
    case Elf64OSABI::MODESTO:
        os << "MODESTO";
        break;
    case Elf64OSABI::OPENBSD:
        os << "OPENBSD";
        break;
    case Elf64OSABI::OPENVMS:
        os << "OPENVMS";
        break;
    case Elf64OSABI::NSK:
        os << "NSK";
        break;
    default:
        os << "Unknown";
        break;
    }
    return os;
}
inline std::ostream &operator<<(std::ostream &os, Elf64SectionType section)
{
    switch (section)
    {
    case Elf64SectionType::_NULL:
        os << "NULL";
        break;
    case Elf64SectionType::PROGBITS:
        os << "PROGBITS";
        break;
    case Elf64SectionType::SYMTAB:
        os << "SYMTAB";
        break;
    case Elf64SectionType::STRTAB:
        os << "STRTAB";
        break;
    case Elf64SectionType::RELA:
        os << "RELA";
        break;
    case Elf64SectionType::HASH:
        os << "HASH";
        break;
    case Elf64SectionType::DYNAMIC:
        os << "DYNAMIC";
        break;
    case Elf64SectionType::NOTE:
        os << "NOTE";
        break;
    case Elf64SectionType::NOBITS:
        os << "NOBITS";
        break;
    case Elf64SectionType::REL:
        os << "REL";
        break;
    case Elf64SectionType::SHLIB:
        os << "SHLIB";
        break;
    case Elf64SectionType::DYNSYM:
        os << "DYNSYM";
        break;
    case Elf64SectionType::INIT_ARRAY:
        os << "INIT_ARRAY";
        break;
    case Elf64SectionType::FINI_ARRAY:
        os << "FINI_ARRAY";
        break;
    case Elf64SectionType::PREINIT_ARRAY:
        os << "PREINIT_ARRAY";
        break;
    case Elf64SectionType::GROUP:
        os << "GROUP";
        break;
    case Elf64SectionType::SYMTAB_SHNDX:
        os << "SYMTAB_SHNDX";
        break;
    case Elf64SectionType::LOOS:
        os << "LOOS";
        break;
    case Elf64SectionType::HIOS:
        os << "HIOS";
        break;
    case Elf64SectionType::LOPROC:
        os << "LOPROC";
        break;
    case Elf64SectionType::HIPROC:
        os << "HIPROC";
        break;
    case Elf64SectionType::LOUSER:
        os << "LOUSER";
        break;
    case Elf64SectionType::HIUSER:
        os << "HIUSER";
        break;
    default:
        os << "Unknown";
        break;
    }
    return os;
}

inline std::ostream &operator<<(std::ostream &os, Elf64ProgramType section)
{
    switch (section)
    {
    case Elf64ProgramType::_NULL:
        os << "NULL";
        break;
    case Elf64ProgramType::PT_LOAD:
        os << "LOAD";
        break;
    case Elf64ProgramType::PT_DYNAMIC:
        os << "DYNAMIC";
        break;
    case Elf64ProgramType::PT_INTERP:
        os << "INTERP";
        break;
    case Elf64ProgramType::NOTE:
        os << "NOTE";
        break;
    case Elf64ProgramType::SHLIB:
        os << "SHLIB";
        break;
    case Elf64ProgramType::PHDR:
        os << "PHDR";
        break;
    case Elf64ProgramType::TLS:
        os << "TLS";
        break;
    case Elf64ProgramType::LOOS:
        os << "LOOS";
        break;
    case Elf64ProgramType::HIOS:
        os << "HIOS";
        break;
    case Elf64ProgramType::LOPROC:
        os << "LOPROC";
        break;
    case Elf64ProgramType::HIPROC:
        os << "HIPROC";
        break;
    default:
        os << "Unknown";
        break;
    }
    return os;
}

inline std::ostream &operator<<(std::ostream &os, Elf64ProgramFlags flags)
{
    switch (flags)
    {
    case Elf64ProgramFlags::X:
        os << "X";
        break;
    case Elf64ProgramFlags::W:
        os << "W";
        break;
    case Elf64ProgramFlags::WX:
        os << "WX";
        break;
    case Elf64ProgramFlags::R:
        os << "R";
        break;
    case Elf64ProgramFlags::RW:
        os << "RW";
        break;
    case Elf64ProgramFlags::RX:
        os << "RX";
        break;
    case Elf64ProgramFlags::RWX:
        os << "RWX";
        break;
    case Elf64ProgramFlags::MASKOS:
        os << "MASKOS";
        break;
    case Elf64ProgramFlags::MASKPROC:
        os << "MASKPROC";
        break;
    default:
        os << "Unknown";
        break;
    }
    return os;
}

void printElf64Header(const Elf64Header &header)
{
    std::cout << "Elf64Header:" << std::endl;
    std::cout << "  e_ident.ei_magic: " << std::hex << std::setw(2) << std::setfill('0');
    for (int i = 0; i < 4; ++i)
        std::cout << static_cast<int>(header.e_ident.ei_magic[i]) << " ";
    std::cout << std::dec << std::endl;
    std::cout << "  e_ident.ei_class: " << header.e_ident.ei_class << std::endl;
    std::cout << "  e_ident.ei_data_encoding: " << static_cast<int>(header.e_ident.ei_data_encoding) << std::endl;
    std::cout << "  e_ident.ei_version: " << static_cast<int>(header.e_ident.ei_version) << std::endl;
    std::cout << "  e_ident.ei_os_abi: " << header.e_ident.ei_os_abi << std::endl;
    std::cout << "  e_ident.ei_abi_version: " << static_cast<int>(header.e_ident.ei_abi_version) << std::endl;
    std::cout << "  e_type: " << header.e_type << std::endl;
    std::cout << "  e_machine: " << header.e_machine << std::endl;
    std::cout << "  e_version: " << header.e_version << std::endl;
    std::cout << "  e_entry: " << header.e_entry << std::endl;
    std::cout << "  e_phoff: " << header.e_phoff << std::endl;
    std::cout << "  e_shoff: " << header.e_shoff << std::endl;
    std::cout << "  e_flags: " << header.e_flags << std::endl;
    std::cout << "  e_ehsize: " << header.e_ehsize << std::endl;
    std::cout << "  e_phentsize: " << header.e_phentsize << std::endl;
    std::cout << "  e_phnum: " << header.e_phnum << std::endl;
    std::cout << "  e_shentsize: " << header.e_shentsize << std::endl;
    std::cout << "  e_shnum: " << header.e_shnum << std::endl;
    std::cout << "  e_shstrndx: " << header.e_shstrndx << std::endl;
    std::cout << std::endl;
}

void printElf64SectionHeader(const Elf64SectionHeader &section_header,
                             const std::map<Elf64_Off, std::string> &section_headers_names)
{
    std::cout << "Elf64SectionHeader:" << std::endl;
    if (auto name = section_headers_names.find(section_header.sh_name); name != section_headers_names.end())
        std::cout << "  sh_name: " << name->second << std::endl;
    else
        std::cout << "  sh_name: " << section_header.sh_name << std::endl;
    std::cout << "  sh_type: " << section_header.sh_type << std::endl;
    std::cout << "  sh_flags: " << section_header.sh_flags << std::endl;
    std::cout << "  sh_addr: " << section_header.sh_addr << std::endl;
    std::cout << "  sh_offset: " << section_header.sh_offset << std::endl;
    std::cout << "  sh_size: " << section_header.sh_size << std::endl;
    std::cout << "  sh_link: " << section_header.sh_link << std::endl;
    std::cout << "  sh_info: " << section_header.sh_info << std::endl;
    std::cout << "  sh_addralign: " << section_header.sh_addralign << std::endl;
    std::cout << "  sh_entsize: " << section_header.sh_entsize << std::endl;
    std::cout << std::endl;
}

void printElf64ProgramHeader(const Elf64ProgramHeader &programHeader)
{
    std::cout << "Elf64ProgramHeader:" << std::endl;
    std::cout << "  p_type: " << programHeader.p_type << std::endl;
    std::cout << "  p_flags: " << programHeader.p_flags << std::endl;
    std::cout << "  p_offset: " << programHeader.p_offset << std::endl;
    std::cout << "  p_vaddr: " << programHeader.p_vaddr << std::endl;
    std::cout << "  p_paddr: " << programHeader.p_paddr << std::endl;
    std::cout << "  p_filesz: " << programHeader.p_filesz << std::endl;
    std::cout << "  p_memsz: " << programHeader.p_memsz << std::endl;
    std::cout << "  p_align: " << programHeader.p_align << std::endl;
    std::cout << std::endl;
}
} // namespace libos::extensions::elfloader