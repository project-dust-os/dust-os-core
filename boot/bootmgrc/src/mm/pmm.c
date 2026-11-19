#include <include/efi.h>
#include <stdint.h>
#include "pmm.h"

static uint64_t *check_memory(uint64_t *addr, uint64_t *info, size_t size)
{
	uint64_t descriptor;

	for (uint64_t i = 0; i < descriptor; i++) {
		if (addr[i] == descriptor) {
			addr[i] += descriptor;
			addr[i] += size;
		}
	}
}
