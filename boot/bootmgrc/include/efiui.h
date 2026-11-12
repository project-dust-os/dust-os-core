#ifndef _EFIUI_H
#define _EFIUI_H

/* ============ Graphics Output Protocol (GOP) ============ */
typedef struct {
	uint32_t MaxMode;
	uint32_t Mode;
	void *Info; // EFI_GRAPHICS_OUTPUT_MODE_INFORMATION*
	uintn_t SizeOfInfo;
	uint64_t FrameBufferBase;
	uintn_t FrameBufferSize;
} EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE;

typedef struct {
	void *QueryMode;
	void *SetMode;
	void *Blt;
	EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE *Mode;
} efi_graphics_output_protocol;

/* Pixel format */
typedef enum {
	PixelRedGreenBlueReserved8BitPerColor,
	PixelBlueGreenRedReserved8BitPerColor,
	PixelBitMask,
	PixelBltOnly,
	PixelFormatMax
} efi_graphics_pixel_format;

typedef struct {
	uint32_t Version;
	uint32_t HorizontalResolution;
	uint32_t VerticalResolution;
	efi_graphics_pixel_format PixelFormat;
	void *PixelInformation; // EFI_PIXEL_BITMASK*
	uint32_t PixelsPerScanLine;
} EFI_GRAPHICS_OUTPUT_MODE_INFORMATION;

#endif // _EFIUI_H
