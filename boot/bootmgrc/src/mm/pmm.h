#ifndef _PHYS_MEMORY_H
#define _PHYS_MEMORY_H

#include <include/efi.h>
#include <stdint.h>

#define MEMMAP_USABLE 1
#define MEMMAP_REVERSED 2
#define MEMMAP_BAD_MEMORY 3
#define MEMMAP_ACPI_RECLAIMABLE 4
#define MEMMAP_ACPI_NVS 5
#define MEMMAP_KERNEL_AND_MODULES 0x1000
#define MEMMAP_FRAMEBUFFER 0x1001
#define MEMMAP_EFI_RECLAIMABLE 0x2000

struct memory_entry {
	uint64_t base;
	uint64_t length;
	uint32_t type;
	uint32_t count;
};

struct memory_info {
	uint64_t min;
	uint64_t max;
	uint64_t used_memory;
	uint32_t unused;
};

#define memset __buildin_memset
#define memcpy __buildin_memcpy

static void *memset(void *restrict, uint64_t descriptor);
static void *memcpy(void *restrict, const void *_Nonull, size_t size);

static void *mem_alloc(size_t size);
static void *mem_free(void *ptr);

#endif // _PHYS_MEMORY_H
