#ifndef _EFI_FS_H
#define _EFI_FS_H

#define EFI_PARTITION_SIGNATURE 0x5053595320494249
#define EFI_PARTITION_REVISION 0x00010001
#define MIN_EFI_PARTITION_BLOCK_SIZE 512
#define EFI_PARTITION_LBA 1
#define EFI_PARTITION_GUID_SIZE 16

typedef struct {
	EFI_TABLE_HEADER Hdr;
	EFI_LBA FirstUsableLba;
	EFI_LBA LastUsableLba;
	uint8_t DiskGuid[EFI_PARTITION_GUID_SIZE];
	EFI_LBA PartitionEntryLba;
	uint32_t NumberOfPartitionEntries;
	uint32_t SizeOfPartitionEntry;
	uint32_t PartitionEntryArrayCrc32;
} EFI_PARTITION_TABLE_HEADER;

#define EFI_FILE_HEADER_SIGNATURE 0x454c494620494249
#define EFI_FILE_HEADER_REVISION 0x00010000
#define EFI_FILE_STRING_SIZE 260

typedef struct {
	EFI_TABLE_HEADER Hdr;
	uint32_t Class;
	uint32_t LbaOffset;
	EFI_LBA Parrent;
	uint64_t FileSize;
	uint64_t FileAttributes;
	EFI_TIME FileCreateTime;
	EFI_TIME FileLastAccessTime;
	EFI_GUID VendorGuid;
	char16_t FileName[EFI_FILE_STRING_SIZE];
} efi_file_header;

/* File modes */
#define EFI_FILE_MODE_READ 0x0000000000000001
#define EFI_FILE_MODE_WRITE 0x0000000000000002
#define EFI_FILE_MODE_CREATE 0x8000000000000000

/* File attributes */
#define EFI_FILE_READ_ONLY 0x0000000000000001
#define EFI_FILE_HIDDEN 0x0000000000000002
#define EFI_FILE_SYSTEM 0x0000000000000004
#define EFI_FILE_RESERVED 0x0000000000000008
#define EFI_FILE_DIRECTORY 0x0000000000000010
#define EFI_FILE_ARCHIVE 0x0000000000000020
#define EFI_FILE_VALID_ATTR 0x0000000000000037

/* ============ File Info (for GetInfo) ============ */
#define EFI_FILE_INFO_GUID \
	{ 0x09576e92,      \
	  0x6d3f,          \
	  0x11d2,          \
	  { 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } }

typedef struct {
	uint64_t size;
	uint64_t file_size;
	uint64_t physical_size;
	/* ... other fields not needed ... */
} efi_file_info;

/* ============ Loaded Image Protocol ============ */
/* Info tentang image yang sedang jalan (bootloader itu sendiri) */
typedef struct {
	uint32_t Revision;
	EFI_HANLDE ParentHandle;
	void *SystemTable;
	EFI_HANDLE DeviceHandle;
	void *FilePath;
	void *Reserved;
	uint32_t LoadOptionsSize;
	void *LoadOptions;
	void *ImageBase; // ImageBase
	uint64_t ImageSize; // ImageSize
	uintn_t ImageCodeType; // ImageCodeType
	uintn_t ImageDataType; // ImageDataType
	void *Unload; // Unload function
} EFI_LOADED_IMAGE_PROTOCOL;

/* ======= HELPER FILESYSTEM UEFI ======= */
EFI_STATUS(EFIAPI *open)(uint16_t *FileName, uint64_t OpenMode,
			 uint64_t Attributes);

EFI_STATUS(EFIAPI *close)(void);

EFI_STATUS(EFIAPI *delete)(void);

EFI_STATUS(EFIAPI *read)(uintn_t *BufferSize, void *Buffer);

EFI_STATUS(EFIAPI *write)(uintn_t BufferSize, void *Buffer);

EFI_STATUS(EFIAPI *get_position)(uint64_t *Position);

EFI_STATUS(EFIAPI *set_position)(uint64_t Position);

EFI_STATUS(EFIAPI *get_info)(EFI_GUID *InformationType, uintn_t *BufferSize,
			     void *Buffer);

EFI_STATUS(EFIAPI *set_info)(EFI_GUID *InformationType, uintn_t BufferSize,
			     void *Buffer);

EFI_STATUS(EFIAPI *flush)(void);

/* ============ Block I/O Protocol ============ */
typedef struct _efi_block_io_protocol {
	void *Media; // EFI_BLOCK_IO_MEDIA* (Media)
	void *FlushBlocks;
} efi_block_io_protocol;

typedef struct {
	uint32_t MediaId;
	boolean RemovableMedia;
	boolean MediaPresent;
	boolean LogicalPartition;
	boolean ReadOnly;
	boolean WriteCaching;
	uint32_t BlockSize; // BlockSize
	uint32_t IoAlign; // IoAlign
	EFI_LBA LastBlock; // LastBlock
} efi_block_io_media;

EFI_STATUS(EFIAPI *reset)(boolean ExtendedVerification);

EFI_STATUS(EFIAPI *read_blocks)(uint32 MediaId, EFI_LBA Lba, uintn_t BufferSize,
				void *Buffer);

EFI_STATUS(EFIAPI *write_blocks)(uint32_t MediaId, EFI_LBA Lba,
				 uintn_t BufferSize, void *Buffer);

#endif // _EFI_FS_H
