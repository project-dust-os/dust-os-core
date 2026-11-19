#ifndef _BOOTLOADER_GDT_H
#define _BOOTLOADER_GDT_H

#include <stdint.h>

struct gdtr {
	uint16_t limit;
	uint64_t ptr;
} __attribute__((packed));

struct desciptor {
	uint16_t limit;
	uint16_t base_low;
	uint8_t base_mid;
	uint8_t access;
	uint8_t base_hi;
} __attribute__((packed));

void gdt_init(void);

#endif // _BOOTLOADER_GDT_H
