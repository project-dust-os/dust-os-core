#ifndef _EFIGPT_H
#define _EFIGPT_H

typedef struct {
	EFI_LBA MyLba;
	EFI_LBA AlternativeLba;
	EFI_LBA FirstUsableLba;
	EFI_LBA LastUsableLba;
	EFI_LBA PartisionEntrylba;
	EFI_GUID DiskGuid;
	uint32_t NumberOfPartisionEntries;
	uint32_t SizeOfPartisionEntries;
	uint32_t PartisionEntryArray;
} EFI_PARTISION_TABLE_HEADER;

#define EFI_PTAB_HEADER_ID "EFI PART"

typedef struct {
	EFI_LBA StartingLba;
	EFI_LBA EndingLba;
	EFI_LBA PartisionTypeGuid;
	EFI_GUID UniquePartisionGuid;
	uint64_t Attributes;
	char16_t PartisionName[45];
} EFI_PARTITION_ENTRY;

// EFI partision attributes
#define EFI_PART_USED_BY_EFI 0x0000000000000001
#define EFI_PART_REQUIRED_TO_FUNCTION 0x0000000000000002
#define EFI_PART_USED_BY_OS 0x0000000000000004
#define EFI_PART_REQUIRED_BY_OS 0x0000000000000008
#define EFI_PART_BACKUP_REQUIRED 0x0000000000000010
#define EFI_PART_USER_DATA 0x0000000000000020
#define EFI_PART_CRITICAL_USER_DATA 0x0000000000000040
#define EFI_PART_REDUNDANT_PARTITION 0x0000000000000080

#define EFI_PART_TYPE_UNUSED_GUID \
	{ 0x00000000,             \
	  0x0000,                 \
	  0x0000,                 \
	  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } }

#define EFI_PART_TYPE_EFI_SYSTEM_PART_GUID \
	{ 0xc12a7328,                      \
	  0xf81f,                          \
	  0x11d2,                          \
	  { 0xba, 0x4b, 0x00, 0xa0, 0xc9, 0x3e, 0xc9, 0x3b } }

#define EFI_PART_TYPE_LEGACY_MBR_GUID \
	{ 0x024dee41,                 \
	  0x33e7,                     \
	  0x11d3,                     \
	  { 0x9d, 0x69, 0x00, 0x08, 0xc7, 0x81, 0xf3, 0x9f } }

#define EFI_FILE_INFO_GUID \
	{ 0x09576e92,      \
	  0x6d3f,          \
	  0x11d2,          \
	  { 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } }

#endif // _EFIGPT_H
