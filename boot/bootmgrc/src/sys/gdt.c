#include "gdt.h"
#include <include/efi.h>
#include <mm/pmm.h>

static struct desciptor gdt_desc[] = { { 0 },
				       { .limit = 0xffff,
					 .base_low = 0x0000,
					 .base_mid = 0x00,
					 .access = 0b01001101,
					 .base_hi = 0x00 },

				       { .limit = 0xffff,
					 .base_low = 0x0000,
					 .base_mid = 0x00,
					 .access = 0b01101001,
					 .base_hi = 0x00 },

				       { .limit = 0xffff,
					 .base_low = 0x0000,
					 .base_mid = 0x00,
					 .access = 0b11001101,
					 .base_hi = 0x00 },
				       { 0 } };

EFI_STATUS gdt_init(struct gdtr gdt)
{
	struct desciptor *gdt_cpy = (desciptor *)mem_alloc(sizeof(desciptor));
	memcpy(gdt_cpy, desciptor, sizeof(desciptor));
	gdt.ptr = (uintptr_t)gdt_cpy;
}
