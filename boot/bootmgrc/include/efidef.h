#ifndef _EFIDEF_H
#define _EFIDEF_H

#define EFI_SUCCESS	      0
#define EFI_LOAD_ERROR	      (1 | (1ULL << 63))
#define EFI_INVALID_PARAMETER (2 | (1ULL << 63))
#define EFI_UNSUPPORTED	      (3 | (1ULL << 63))
#define EFI_BAD_BUFFER_SIZE   (4 | (1ULL << 63))
#define EFI_BUFFER_TOO_SMALL  (5 | (1ULL << 63))
#define EFI_NOT_READY	      (6 | (1ULL << 63))
#define EFI_DEVICE_ERROR      (7 | (1ULL << 63))
#define EFI_WRITE_PROTECTED   (8 | (1ULL << 63))
#define EFI_OUT_OF_RESOURCES  (9 | (1ULL << 63))
#define EFI_NOT_FOUND	      (14 | (1ULL << 63))

#define EFI_ERROR(status)     (((intn)(status)) < 0)

typedef struct {
	uint32_t data1;
	uint16_t data2;
	uint16_t data3;
	uint8_t data4[8];
} EFI_GUID;

typedef struct {
	uint64_t Signature;
	uint32_t Revision;
	uint32_t HeaderSize;
	uint32_t Crc32;
	uint32_t Reserved;
} EFI_TABLE_HEADER;

typedef struct {
	uint32_t NanoSecond;
	uint16_t Year;
	uint16_t TimeZone;
	uint8_t Day;
	uint8_t Hour;
	uint8_t Minute;
	uint8_t Second;
	uint8_t Daylight;
	uint8_t Pad1;
	uint8_t Pad2;
} EFI_TIME;

/* ========================= efi_memory_type ==============================
 * 1. Preserve the attributes for the given range, regardless of what they may
 * be.
 * 2. EfiConventionalMemory must have the WB, SR, and SW attributes when in use.
 * 3. When allocating EfiConventionalMemory, always set its attributes to WB,
 * SR, and SW.
 * 4. When returning EfiConventionalMemory, always set its attributes to WB, SR,
 * and SW.
 * 5. Applies when obtaining the memory map, or during runtime (RT) for
 * runtime-type memory.
 * ======================================================================== */
typedef enum {
	EfiReservedMemoryType,
	EfiLoaderCode,
	EfiLoaderData,
	EfiBootServicesCode,
	EfiBootServicesData,
	EfiRuntimeServicesCode,
	EfiRuntimeServicesData,
	EfiConventionalMemory,
	EfiUnusableMemory,
	EfiACPIReclaimMemory,
	EfiACPIMemoryNVS,
	EfiMemoryMappedIO,
	EfiMemoryMappedIOPortSpace,
	EfiPalCode,
	EfiPersistentMemory,
	EfiMaxMemoryType
} EFI_MEMORY_TYPE;

typedef struct {
	uint32_t Type;		// EFI_MEMORY_TYPE (Type)
	uint32_t Pad;		// Padding untuk alignment (Pad)
	uint64_t PhysicalStart; // Physical address (PhysicalStart)
	uint64_t VirtualStart;	// Virtual address (VirtualStart)
	uint64_t NumberOfPages; // Jumlah halaman 4KB (NumberOfPages)
	uint64_t Attribute;	// Bitmask: UC, WC, WT, WB, UCE, WP, RP, XP, NV,
				// RUNTIME (Attribute)
} EFI_MEMORY_DESCRIPTOR;

typedef struct {
	EFI_TABLE_HEADER Hdr;
	char16_t *FirmwareVendor;
	uint32_t FirmwareRevision;
	EFI_HANDLE ConsoleInHandle;
	void *ConIn; // Simple Text Input Protocol
	EFI_HANDLE ConsoleOutHandle;
	void *ConOut; // Simple Text Output Protocol
	EFI_HANDLE StandardErrorHandle;
	void *StdErr;	       // Simple Text Output Protocol
	void *RuntimeServices; // EFI_RUNTIME_SERVICES*
	void *BootServices;    // EFI_BOOT_SERVICES*
	uintn_t NumberOfTableEntries;
	void *ConfigurationTable; // EFI_CONFIGURATION_TABLE*
} EFI_SYSTEM_TABLE;

typedef struct {
	EFI_TABLE_HEADER Hdr;

	/* Task Priority */
	void *RaiseTPL;
	void *RestoreTPL;

	/* Event & Timer */
	void *CreateEvent;
	void *SetTimer;
	void *WaitForEvent;
	void *SignalEvent;
	void *CloseEvent;
	void *CheckEvent;

	/* Protocol Handler */
	void *InstallProtocolInterface;
	void *ReinstallProtocolInterface;
	void *UninstallProtocolInterface;
	void *HandleProtocol;
	void *Reserved;
	void *RegisterProtocolNotify;
	void *LocateHandle;
	void *LocateDevicePath;
	void *InstallConfigurationTable;

	/* Image */
	void *LoadImage;
	void *StartImage;
	void *Exit;
	void *UnloadImage;

	/* Misc */
	void *GetNextMonotonicCount;
	void *Stall;
	void *SetWatchdogTimer;

	/* DriverSupport */
	void *ConnectController;
	void *DisconnectController;

	/* Open/Close Protocol */
	void *OpenProtocol;
	void *CloseProtocol;
	void *OpenProtocolInformation;

	/* Library */
	void *ProtocolsPerHandle;
	void *LocateHandleBuffer;
	void *LocateProtocol;
	void *InstallMultipleProtocolInterfaces;
	void *UninstallMultipleProtocolInterfaces;

	/* CRC */
	void *CalculateCrc32;

	/* Memory */
	void *CopyMem;
	void *SetMem;
	void *CreateEventEx;
} EFI_BOOT_SERVICES;

typedef struct {
	void *Reset;
	void *TestString;
	void *QueryMode;
	void *SetMode;
	void *SetAttribute;

	void *SetCursorPosition;
	void *EnableCursor;
	void *Mode; // Pointer ke SIMPLE_TEXT_OUTPUT_MODE
} EFI_SIMPLE_OUTPUT_PROTOCOL;

// exit boot services
EFI_STATUS(EFIAPI *ExitBootServices)(EFI_HANDLE ImageHandle, uintn_t MapKey);

// Memory for booting
EFI_STATUS(EFIAPI *AllocatePages)(uintn_t Type, uintn_t MemoryType,
    uintn_t Pages, uint64_t *Memory);

EFI_STATUS(EFIAPI *FreePages)(uint64_t Memory, uintn_t Pages);

EFI_STATUS(EFIAPI *GetMemoryMap)(uintn_t *MemoryMapSize,
    EFI_MEMORY_DESCRIPTOR *MemoryMap, uintn_t *MapKey, uintn_t *DescriptorSize,
    uint32_t *DescriptorVersion);

EFI_STATUS(EFIAPI *AllocatePool)(uintn_t PoolType, uintn_t Size, void **Buffer);

EFI_STATUS(EFIAPI *FreePool)(void *Buffer);

// Sistem output protocol uefi
EFI_STATUS(EFIAPI *OutputString)(char16_t *String);

EFI_STATUS(EFIAPI *ClearScreen)(void);

// Memory cacheability attribute
#define EFI_MEMORY_UC  0x0000000000000001
#define EFI_MEMORY_WC  0x0000000000000002
#define EFI_MEMORY_WT  0x0000000000000004
#define EFI_MEMORY_WB  0x0000000000000008
#define EFI_MEMORY_UCE 0x0000000000000010

// Physical memory protection attribute
#define EFI_MEMORY_WP 0x0000000000001000
#define EFI_MEMORY_RP 0x0000000000002000
#define EFI_MEMORY_XP 0x0000000000004000
#define EFI_MEMORY_RO 0x0000000000020000

// Runtime memory attribute
#define EFI_MEMORY_NV	   0x0000000000008000
#define EFI_MEMORY_RUNTIME 0x8000000000000000

// Other memory attribute
#define EFI_MEMORY_MORE_RELIABLE			   0x0000000000010000
#define EFI_MEMORY_SP					   0x0000000000040000
#define EFI_MEMORY_CPU_CRYPTO				   0x0000000000080000
#define EFI_MEMORY_HOT_PLUGGABLE			   0x0000000000100000
#define EFI_MEMORY_ISA_VALID				   0x4000000000000000
#define EFI_MEMORY_ISA_MASK				   0x0FFFF00000000000

#define EFI_OS_INDICATIONS_BOOT_TO_FW_UI		   0x0000000000000001
#define EFI_OS_INDICATIONS_TIMESTAMP_REVOCATION		   0x0000000000000002
#define EFI_OS_INDICATIONS_FILE_CAPSULE_DELIVERY_SUPPORTED 0x0000000000000004
#define EFI_OS_INDICATIONS_FMP_CAPSULE_SUPPORTED	   0x0000000000000008
#define EFI_OS_INDICATIONS_CAPSULE_RESULT_VAR_SUPPORTED	   0x0000000000000011
#define EFI_OS_INDICATIONS_START_OS_RECOVERY		   0x0000000000000020
#define EFI_OS_INDICATIONS_START_PLATFORM_RECOVERY	   0x0000000000000040
#define EFI_OS_INDICATIONS_JSON_CONFIG_DATA_REFRESH	   0x0000000000000080

#define EFI_OPTIONAL_PTR				   0x00000001
#define EFI_INTERNAL_FUNC				   0x00000002
#define EFI_INTERNAL_PTR				   0x00000004

#endif // _EFIDEF_H
