#include <uefi.h>

EFI_STATUS EFIAPI efi_main(EFI_HANDLE ImageHandle,
			   EFI_SYSTEM_TABLE *SystemTable)
{
	SystemTable->ConOut->OutputString(SystemTable->ConOut,
					  u"Halo, Bootloader uefi ku\r\n");
	while (1)
		;
	return EFI_SUCCESS;
}
