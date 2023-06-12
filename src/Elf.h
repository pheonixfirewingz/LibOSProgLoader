#pragma once
// spec: https://refspecs.linuxfoundation.org/elf/gabi4+/contents.html
namespace libos::extensions::elfloader
{
// ELF-64 Data Types
using Elf64_Addr = unsigned long long;  // 8 bytes
using Elf64_Off = unsigned long long;   // 8 bytes
using Elf64_Half = unsigned short;      // 2 bytes
using Elf64_Word = unsigned int;        // 4 bytes
using Elf64_Sword = signed int;         // 4 bytes
using Elf64_Xword = unsigned long long; // 8 bytes
using Elf64_Sxword = signed long long;  // 8 bytes
using Elf64_Byte = unsigned char;       // 1 byte
// elf enums interpritation
enum class Elf64Type : Elf64_Half
{
    NONE = 0,        //	No file type
    REL = 1,         //	Relocatable file
    EXEC = 2,        //	Executable file
    DYN = 3,         //	Shared object file
    CORE = 4,        //	Core file
    LOOS = 0xfe00,   //	Operating system - specific
    HIOS = 0xfeff,   //	Operating system - specific
    LOPROC = 0xff00, //	Processor - specific
    HIPROC = 0xffff, //	Processor - specific
};
enum class Elf64Machine : Elf64_Half
{
    NONE = 0,  //	No machine
    M32 = 1,   // AT & T WE 32100
    SPARC = 2, // SPARC
    I386 = 3,  // Intel 80386
    K68 = 4,   // Motorola 68000
    K88 = 5,   // Motorola 88000
    // reserved	6	Reserved for future use(was 486)
    I860 = 7,         //	Intel 80860
    MIPS = 8,         // MIPS I Architecture
    S370 = 9,         // IBM System / 370 Processor
    MIPS_RS3_LE = 10, //	MIPS RS3000 Little - endian
    // reserved	11 - 14	Reserved for future use
    PARISC = 15, //	Hewlett - Packard PA - RISC
    // reserved	16	Reserved for future use
    VPP500 = 17,      //	Fujitsu VPP500
    SPARC32PLUS = 18, //	Enhanced instruction set SPARC
    I960 = 19,        //	 Intel 80960
    PPC = 20,         // PowerPC
    PPC64 = 21,       // 64 - bit PowerPC
    S390 = 22,        // IBM System / 390 Processor
    // reserved	23 - 35	Reserved for future use
    V800 = 36,      // NEC V800
    FR20 = 37,      // Fujitsu FR20
    RH32 = 38,      // TRW RH - 32
    RCE = 39,       // Motorola RCE
    ARM = 40,       // Advanced RISC Machines ARM
    ALPHA = 41,     // Digital Alpha
    SH = 42,        // Hitachi SH
    SPARCV9 = 43,   // SPARC Version 9
    TRICORE = 44,   //	Siemens TriCore embedded processor
    ARC = 45,       // Argonaut RISC Core, Argonaut Technologies Inc.
    H8_300 = 46,    // Hitachi H8 / 300
    H8_300H = 47,   // Hitachi H8 / 300H
    H8S = 48,       // Hitachi H8S
    H8_500 = 49,    // Hitachi H8 / 500
    IA_64 = 50,     // Intel IA - 64 processor architecture
    MIPS_X = 51,    // Stanford MIPS - X
    COLDFIRE = 52,  // Motorola ColdFire
    _68HC12 = 53,   // Motorola M68HC12
    MMA = 54,       // Fujitsu MMA Multimedia Accelerator
    PCP = 55,       // Siemens PCP
    NCPU = 56,      // Sony nCPU embedded RISC processor
    NDR1 = 57,      // Denso NDR1 microprocessor
    STARCORE = 58,  // Motorola Star * Core processor
    ME16 = 59,      // Toyota ME16 processor
    ST100 = 60,     // STMicroelectronics ST100 processor
    TINYJ = 61,     // Advanced Logic Corp.TinyJ embedded processor family
    X86_64 = 62,    // AMD x86 - 64 architecture
    PDSP = 63,      // Sony DSP Processor
    PDP10 = 64,     // Digital Equipment Corp.PDP - 10
    PDP11 = 65,     // Digital Equipment Corp.PDP - 11
    FX66 = 66,      // Siemens FX66 microcontroller
    ST9PLUS = 67,   // STMicroelectronics ST9 + 8 / 16 bit microcontroller
    ST7 = 68,       // STMicroelectronics ST7 8 - bit microcontroller
    _68HC16 = 69,   //	Motorola MC68HC16 Microcontroller
    _68HC11 = 70,   // Motorola MC68HC11 Microcontroller
    _68HC08 = 71,   // Motorola MC68HC08 Microcontroller
    _68HC05 = 72,   //	Motorola MC68HC05 Microcontroller
    SVX = 73,       // Silicon Graphics SVx
    ST19 = 74,      // STMicroelectronics ST19 8 - bit microcontroller
    VAX = 75,       // Digital VAX
    CRIS = 76,      // Axis Communications 32 - bit embedded processor
    JAVELIN = 77,   // Infineon Technologies 32 - bit embedded processor
    FIREPATH = 78,  // Element 14 64 - bit DSP Processor
    ZSP = 79,       // LSI Logic 16 - bit DSP Processor
    MMIX = 80,      // Donald Knuth's educational 64-bit processor
    HUANY = 81,     // Harvard University machine - independent object files
    PRISM = 82,     // SiTera Prism
    AVR = 83,       // Atmel AVR 8 - bit microcontroller
    FR30 = 84,      // Fujitsu FR30
    D10V = 85,      // Mitsubishi D10V
    D30V = 86,      // Mitsubishi D30V
    V850 = 87,      // NEC v850
    M32R = 88,      // Mitsubishi M32R
    MN10300 = 89,   // Matsushita MN10300
    MN10200 = 90,   // Matsushita MN10200
    PJ = 91,        // picoJava
    OPENRISC = 92,  // OpenRISC 32 - bit embedded processor
    ARC_A5 = 93,    // ARC Cores Tangent - A5
    XTENSA = 94,    // Tensilica Xtensa Architecture
    VIDEOCORE = 95, // Alphamosaic VideoCore processor
    TMM_GPP = 96,   // Thompson Multimedia General Purpose Processor
    NS32K = 97,     // National Semiconductor 32000 series
    TPC = 98,       // Tenor Network TPC processor
    SNP1K = 99,     // Trebia SNP 1000 processor
    ST200 = 100,    // STMicroelectronics(www.st.com) ST200 microcontroller
};

enum class Elf64Class : Elf64_Byte
{
    NONE = 0, // Invalid class
    _32 = 1,  // 32-bit objects
    _64 = 2,  // 64-bit objects
};

enum class Elf64OSABI : Elf64_Byte
{
    NONE = 0,     // No extensions or unspecified
    HPUX = 1,     // Hewlett - Packard HP - UX
    NETBSD = 2,   // NetBSD
    LINUX = 3,    // Linux
    SOLARIS = 6,  // Sun Solaris
    AIX = 7,      // AIX
    IRIX = 8,     // IRIX
    FREEBSD = 9,  // FreeBSD
    TRU64 = 10,   // Compaq TRU64 UNIX
    MODESTO = 11, // Novell Modesto
    OPENBSD = 12, // Open BSD
    OPENVMS = 13, // Open VMS
    NSK = 14,     // Hewlett - Packard Non - Stop Kernel
                  // 64 - 255	Architecture - specific value range
};
#if ON_WINDOWS
#    pragma pack(push, 1)
#endif
struct Elf64Header
{
#if ON_WINDOWS
#    pragma pack(push, 1)
#endif
    struct
    {
        Elf64_Byte
            ei_magic[4]; // A file's first 4 bytes hold a ``magic number,'' identifying the file as an ELF object file.
        Elf64Class ei_class;         // The next byte, e_ident[EI_CLASS], identifies the file's class, or capacity.
        Elf64_Byte ei_data_encoding; // Byte e_ident[EI_DATA] specifies the encoding of both the data structures used by
                                     // object file container and data contained in object file sections. The following
                                     // encodings are currently defined.
        Elf64_Byte ei_version; // Byte e_ident[EI_VERSION] specifies the ELF header version number. Currently, this
                               // value must be EV_CURRENT
        Elf64OSABI ei_os_abi;
        /*Byte e_ident[EI_OSABI] identifies the OS- or ABI-specific ELF extensions used by this file. Some fields in
        other ELF structures have flags and values that have operating system and/or ABI specific meanings; the
        interpretation of those fields is determined by the value of this byte. If the object file does not use any
        extensions, it is recommended that this byte be set to 0. If the value for this byte is 64 through 255, its
        meaning depends on the value of the e_machine header member. The ABI processor supplement for an architecture
        can define its own associated set of values for this byte in this range. If the processor supplement does not
        specify a set of values, one of the following values shall be used, where 0 can also be taken to mean
        unspecified.*/
        Elf64_Byte ei_abi_version;
        /*Byte e_ident[EI_ABIVERSION] identifies the version of the ABI to which the object is targeted. This field is
        used to distinguish among incompatible versions of an ABI. The interpretation of this version number is
        dependent on the ABI identified by the EI_OSABI field. If no values are specified for the EI_OSABI field by the
        processor supplement or no version values are specified for the ABI determined by a particular value of the
        EI_OSABI byte, the value 0 shall be used for the EI_ABIVERSION byte; it indicates unspecified.*/
        Elf64_Byte ei_padding[7];
    } e_ident;
#if ON_WINDOWS
#    pragma pack(pop) // restore the default packing
#endif
    Elf64Type e_type;       // This member identifies the object file type.
    Elf64Machine e_machine; // This member's value specifies the required architecture for an individual file.
    Elf64_Word e_version;   // This member identifies the object file version.
    Elf64_Addr e_entry;     // This member gives the virtual address to which the system first transfers control, thus
                            // starting the process.If the file has no associated entry point, this member holds zero.
    Elf64_Off e_phoff;  // This member holds the program header table's file offset in bytes. If the file has no program
                        // header table, this member holds zero.
    Elf64_Off e_shoff;  // This member holds the section header table's file offset in bytes. If the file has no section
                        // header table, this member holds zero.
    Elf64_Word e_flags; // This member holds processor - specific flags associated with the file.Flag names take the
                        // form EF_machine_flag.
    Elf64_Half e_ehsize;    // This member holds the ELF header's size in bytes.
    Elf64_Half e_phentsize; // This member holds the size in bytes of one entry in the file's program header table; all
                            // entries are the same size.
    Elf64_Half e_phnum;     // This member holds the number of entries in the program header table.Thus the product of
                            // e_phentsize and e_phnum gives the table's size in bytes. If a file has no program header
                            // table, e_phnum holds the value zero.
    Elf64_Half e_shentsize; // This member holds a section header's size in bytes. A section header is one entry in the
                            // section header table; all entries are the same size.
    Elf64_Half e_shnum;     // This member holds the number of entries in the section header table.Thus the product of
                            // e_shentsize and e_shnum gives the section header table's size in bytes. If a file has no
                            // section header table, e_shnum holds the value zero.
    /*If the number of sections is greater than or equal to SHN_LORESERVE (0xff00), this member has the value zero and
       the actual number of section header table entries is contained in the sh_size field of the section header at
       index 0. (Otherwise, the sh_size member of the initial entry contains 0.)*/
    Elf64_Half e_shstrndx; // This member holds the section header table index of the entry associated with the section
                           // name string table. If the file has no section name string table, this member holds the
                           // value SHN_UNDEF. See ``Sections'' and ``String Table'' below for more information.
    /*If the section name string table section index is greater than or equal to SHN_LORESERVE(0xff00), this member has
    the value SHN_XINDEX(0xffff) and the actual index of the section name string table section is contained in the
    sh_link field of the section header at index 0. (Otherwise, the sh_link member of the initial entry contains 0.)*/
};
#if ON_WINDOWS
#    pragma pack(pop) // restore the default packing
#endif
enum class Elf64SectionType : Elf64_Word
{
    _NULL = 0,
    PROGBITS = 1,
    SYMTAB = 2,
    STRTAB = 3,
    RELA = 4,
    HASH = 5,
    DYNAMIC = 6,
    NOTE = 7,
    NOBITS = 8,
    REL = 9,
    SHLIB = 10,
    DYNSYM = 11,
    INIT_ARRAY = 14,
    FINI_ARRAY = 15,
    PREINIT_ARRAY = 16,
    GROUP = 17,
    SYMTAB_SHNDX = 18,
    LOOS = 0x60000000,
    HIOS = 0x6fffffff,
    LOPROC = 0x70000000,
    HIPROC = 0x7fffffff,
    LOUSER = 0x80000000,
    HIUSER = 0xffffffff,
};

enum class Elf64SectionFlags : Elf64_Xword
{
    WRITE = 0x1,
    ALLOC = 0x2,
    EXECINSTR = 0x4,
    MERGE = 0x10,
    STRINGS = 0x20,
    INFO_LINK = 0x40,
    LINK_ORDER = 0x80,
    OS_NONCONFORMING = 0x100,
    GROUP = 0x200,
    TLS = 0x400,
    /*
#include <iostream>
#include <vector>

enum class Elf64SectionFlags : Elf64_Xword
{
    WRITE = 0x1,
    ALLOC = 0x2,
    EXECINSTR = 0x4,
    MERGE = 0x10,
    STRINGS = 0x20,
    INFO_LINK = 0x40,
    LINK_ORDER = 0x80,
    OS_NONCONFORMING = 0x100,
    GROUP = 0x200,
    TLS = 0x400,
};

std::vector<Elf64SectionFlags> generateCombinations()
{
    std::vector<Elf64SectionFlags> combinations;

    const std::vector<Elf64SectionFlags> flags = {
        Elf64SectionFlags::WRITE,
        Elf64SectionFlags::ALLOC,
        Elf64SectionFlags::EXECINSTR,
        Elf64SectionFlags::MERGE,
        Elf64SectionFlags::STRINGS,
        Elf64SectionFlags::INFO_LINK,
        Elf64SectionFlags::LINK_ORDER,
        Elf64SectionFlags::OS_NONCONFORMING,
        Elf64SectionFlags::GROUP,
        Elf64SectionFlags::TLS
    };

    // Generate combinations
    for (std::size_t i = 0; i < flags.size(); ++i)
    {
        for (std::size_t j = i + 1; j < flags.size(); ++j)
        {
            const Elf64SectionFlags combination = flags[i] | flags[j];
            combinations.push_back(combination);
        }
    }

    return combinations;
}

int main()
{
    std::vector<Elf64SectionFlags> combinations = generateCombinations();

    // Print the generated combinations
    for (const auto& combination : combinations)
    {
        std::cout << static_cast<Elf64_Xword>(combination) << std::endl;
    }

    return 0;
}
    */
};

#if ON_WINDOWS
#    pragma pack(push, 1)
#endif
struct Elf64SectionHeader
{
    Elf64_Word
        sh_name; // This member specifies the name of the section.Its value is an index into the section header string
                 // table section[see ``String Table'' below], giving the location of a null - terminated string.;
    Elf64SectionType sh_type;   // This member categorizes the section's contents and semantics.
    Elf64SectionFlags sh_flags; // Sections support 1 - bit flags that describe miscellaneous attributes.
    Elf64_Addr sh_addr; // If the section will appear in the memory image of a process, this member gives the address at
                        // which the section's first byte should reside. Otherwise, the member contains 0.
    Elf64_Off sh_offset; // This member's value gives the byte offset from the beginning of the file to the first byte
                         // in the section. One section type, SHT_NOBITS described below, occupies no space in the file,
                         // and its sh_offset member locates the conceptual placement in the file.
    Elf64_Xword sh_size; // This member gives the section's size in bytes. Unless the section type is SHT_NOBITS, the
                         // section occupies sh_size bytes in the file. A section of type SHT_NOBITS may have a non-zero
                         // size, but it occupies no space in the file.
    Elf64_Word sh_link;  // This member holds a section header table index link, whose interpretation depends on the
                         // section type.A table below describes the values.
    Elf64_Word sh_info; // This member holds extra information, whose interpretation depends on the section type.A table
                        // below describes the values.If the sh_flags field for this section header includes the
                        // attribute SHF_INFO_LINK, then this member represents a section header table index.
    Elf64_Xword
        sh_addralign; // Some sections have address alignment constraints.For example, if a section holds a doubleword,
                      // the system must ensure doubleword alignment for the entire section.The value of sh_addr must be
                      // congruent to 0, modulo the value of sh_addralign.Currently, only 0 and positive integral powers
                      // of two are allowed.Values 0 and 1 mean the section has no alignment constraints.
    Elf64_Xword sh_entsize; // Some sections hold a table of fixed - size entries, such as a symbol table.For such a
                            // section, this member gives the size in bytes of each entry.The member contains 0 if the
                            // section does not hold a table of fixed - size entries.
};
#if ON_WINDOWS
#    pragma pack(pop) // restore the default packing
#endif
enum class Elf64ProgramType : Elf64_Word
{
    _NULL = 0,
    PT_LOAD = 1,
    PT_DYNAMIC = 2,
    PT_INTERP = 3,
    NOTE = 4,
    SHLIB = 5,
    PHDR = 6,
    TLS = 7,
    LOOS = 0x60000000,
    HIOS = 0x6fffffff,
    LOPROC = 0x70000000,
    HIPROC = 0x7fffffff,
};

enum class Elf64ProgramFlags : Elf64_Word
{
    X = 0x1,         // Execute
    W = 0x2,         // Write
    WX = X | W,      // Execute & Write
    R = 0x4,         // Read
    RW = W | R,      // Read & Execute
    RX = X | R,      // Execute & Read
    RWX = X | W | R, // Read, Write & Execute
};
#if ON_WINDOWS
#    pragma pack(push, 1)
#endif
struct Elf64ProgramHeader
{
    Elf64ProgramType p_type; // This member tells what kind of segment this array element describes or how to interpret
                             // the array element's information.
    Elf64ProgramFlags p_flags; // This member gives the offset from the beginning of the file at which the first byte of
                               // the
                               // segment resides.
    Elf64_Off
        p_offset; // This member gives the virtual address at which the first byte of the segment resides in memory.
    Elf64_Addr p_vaddr;   // On systems for which physical addressing is relevant, this member is reserved for the
                          // segment's physical address. Because System V ignores physical addressing for application
                          // programs, this member has unspecified contents for executable files and shared objects.
    Elf64_Addr p_paddr;   // This member gives the number of bytes in the file image of the segment; it may be zero.
    Elf64_Xword p_filesz; // This member gives flags relevant to the segment.
    Elf64_Xword p_memsz;  // This member gives the number of bytes in the memory image of the segment; it may be zero.
    Elf64_Xword p_align;  // As ``Program Loading'' describes in this chapter of the processor supplement, loadable
                          // process segments must have congruent values for p_vaddr and p_offset, modulo the page size.
                          // This member gives the value to which the segments are aligned in memory and in the file.
                          // Values 0 and 1 mean no alignment is required. Otherwise, p_align should be a positive,
                          // integral power of 2, and p_vaddr should equal p_offset, modulo p_align.
};
#if ON_WINDOWS
#    pragma pack(pop) // restore the default packing
#endif
} // namespace libos::extensions::elfloader