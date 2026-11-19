#ifndef _PE_H
#define _PE_H

#include <stdint.h>

#define IMAGE_DOS_SIGNATURE    0x5A4D	  // MZ
#define IMAGE_OS2_SIGNATURE    0x454E	  // NE
#define IMAGE_OS2_SIGNATURE_LE 0x454C	  // LE
#define IMAGE_NT_SIGNATURE     0x00004550 // PE00
#define IMAGE_EDOS_SIGNATURE   0x44454550 // PEED

typedef struct _IMAGE_DOS_HEADER { // DOS .EXE header
	uint16_t e_magic;	   // Magic number
	uint16_t e_cblp;	   // Bytes on last page of file
	uint16_t e_cp;		   // Pages in file
	uint16_t e_crlc;	   // Relocations
	uint16_t e_cparhdr;	   // Size of header in paragraphs
	uint16_t e_minalloc;	   // Minimum extra paragraphs needed
	uint16_t e_maxalloc;	   // Maximum extra paragraphs needed
	uint16_t e_ss;		   // Initial (relative) SS value
	uint16_t e_sp;		   // Initial SP value
	uint16_t e_csum;	   // Checksum
	uint16_t e_ip;		   // Initial IP value
	uint16_t e_cs;		   // Initial (relative) CS value
	uint16_t e_lfarlc;	   // File address of relocation table
	uint16_t e_ovno;	   // Overlay number
	uint16_t e_res[4];	   // Reserved words
	uint16_t e_oemid;	   // OEM identifier (for e_oeminfo)
	uint16_t e_oeminfo;	   // OEM information; e_oemid specific
	uint16_t e_res2[10];	   // Reserved words
	uint32_t e_lfanew;	   // File address of new exe header
} IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

typedef struct _IMAGE_OS2_HEADER { // OS/2 .EXE header
	uint16_t ne_magic;	   // Magic number
	uint8_t ne_ver;		   // Version number
	uint8_t ne_rev;		   // Revision number
	uint16_t ne_enttab;	   // Offset of Entry Table
	uint16_t ne_cbenttab;	   // Number of bytes in Entry Table
	uint32_t ne_crc;	   // Checksum of whole file
	uint16_t ne_flags;	   // Flag UINT16
	uint16_t ne_autodata;	   // Automatic data segment number
	uint16_t ne_heap;	   // Initial heap allocation
	uint16_t ne_stack;	   // Initial stack allocation
	uint32_t ne_csip;	   // Initial CS:IP setting
	uint32_t ne_sssp;	   // Initial SS:SP setting
	uint16_t ne_cseg;	   // Count of file segments
	uint16_t ne_cmod;	   // Entries in Module Reference Table
	uint16_t ne_cbnrestab;	   // Size of non-resident name table
	uint16_t ne_segtab;	   // Offset of Segment Table
	uint16_t ne_rsrctab;	   // Offset of Resource Table
	uint16_t ne_restab;	   // Offset of resident name table
	uint16_t ne_modtab;	   // Offset of Module Reference Table
	uint16_t ne_imptab;	   // Offset of Imported Names Table
	uint32_t ne_nrestab;	   // Offset of Non-resident Names Table
	uint16_t ne_cmovent;	   // Count of movable entries
	uint16_t ne_align;	   // Segment alignment shift count
	uint16_t ne_cres;	   // Count of resource segments
	uint8_t ne_exetyp;	   // Target Operating system
	uint8_t ne_flagsothers;	   // Other .EXE flags
	uint16_t ne_pretthunks;	   // offset to return thunks
	uint16_t ne_psegrefbytes;  // offset to segment ref. bytes
	uint16_t ne_swaparea;	   // Minimum code swap area size
	uint16_t ne_expver;	   // Expected Windows version number
} IMAGE_OS2_HEADER, *PIMAGE_OS2_HEADER;

//
// File header format.
//

typedef struct _IMAGE_FILE_HEADER {
	uint16_t Machine;
	uint16_t NumberOfSections;
	uint32_t TimeDateStamp;
	uint32_t PointerToSymbolTable;
	uint32_t NumberOfSymbols;
	uint16_t SizeOfOptionalHeader;
	uint16_t Characteristics;
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

#define IMAGE_SIZEOF_FILE_HEADER   20

#define IMAGE_FILE_RELOCS_STRIPPED 0x0001 // Relocation info stripped from file.
#define IMAGE_FILE_EXECUTABLE_IMAGE \
	0x0002 // File is executable  (i.e. no unresolved externel references).
#define IMAGE_FILE_LINE_NUMS_STRIPPED 0x0004 // Line nunbers stripped from file.
#define IMAGE_FILE_LOCAL_SYMS_STRIPPED \
	0x0008 // Local symbols stripped from file.
#define IMAGE_FILE_BYTES_REVERSED_LO \
	0x0080				// Bytes of machine word are reversed.
#define IMAGE_FILE_32BIT_MACHINE 0x0100 // 32 bit word machine.
#define IMAGE_FILE_DEBUG_STRIPPED \
	0x0200 // Debugging info stripped from file in .DBG file
#define IMAGE_FILE_SYSTEM 0x1000 // System File.
#define IMAGE_FILE_DLL	  0x2000 // File is a DLL.
#define IMAGE_FILE_BYTES_REVERSED_HI \
	0x8000 // Bytes of machine word are reversed.

#define IMAGE_FILE_MACHINE_UNKNOWN 0
#define IMAGE_FILE_MACHINE_I386	   0x14c // Intel 386.
#define IMAGE_FILE_MACHINE_R3000   0x162 // MIPS little-endian, 0540 big-endian
#define IMAGE_FILE_MACHINE_R4000   0x166 // MIPS little-endian
#define IMAGE_FILE_MACHINE_ALPHA   0x184 // Alpha_AXP
#define IMAGE_FILE_MACHINE_ARMTHUMB_MIXED 0x1c2	 // Arm/Thumb
#define IMAGE_FILE_MACHINE_POWERPC	  0x1F0	 // IBM PowerPC Little-Endian
#define IMAGE_FILE_MACHINE_IA64		  0x200	 // IA-64
#define IMAGE_FILE_MACHINE_TAHOE	  0x7cc	 // Intel EM machine
#define IMAGE_FILE_MACHINE_EBC		  0xebc	 // EFI Byte Code
#define IMAGE_FILE_MACHINE_X64		  0x8664 // x86_64
//
// Directory format.
//

typedef struct _IMAGE_DATA_DIRECTORY {
	uint32_t VirtualAddress;
	uint32_t Size;
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

#define IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16

#endif
