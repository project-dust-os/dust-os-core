#ifndef _EFI_BOOT_H
#define _EFI_BOOT_H

/* ======== HEADER UEFI ======== */
// standard library freestanding form c
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

// protable executable and assembly in c
#include "exec/elf.h"

#if defined(__x86_64__) || defined(__amd64__) || defined(_M_X64)
#include "exec/setjmp_x86-64.h"
#endif

// including all of header file from uefi bootloader
#include "efidef.h"
#include "eficompiler.h"
#include "efigpt.h"
#include "efifs.h"
#include "efigop.h"

/* ========== THE MAIN DATA TYPE OF UEFI BOOLOADER ========== */
#define EFI_PAGE_SIZE 4096
#define EFI_PAGE_SHIFT 12
#define EFI_SIZE_TO_PAGES(size) (((size) + EFI_PAGE_SIZE - 1) >> EFI_PAGE_SHIFT)

typedef uint8_t boolean;
typedef int8_t char8_t;
typedef int16_t char16_t;
typedef uint64_t uintn_t;
typedef int64_t intn_t;
typedef void *EFI_STATUS;
typedef void *EFI_HANDLE;
typedef void *EFI_EVENT;
typedef uint64_t EFI_LBA;
typedef uintn_t EFI_TPA;

#define EFIERROR(x) (0x8000000000000000 | x)
#define EFI_ERROR_MASK 0x8000000000000000
#define EFI_ERROR_OEM(x) (0xC000000000000000 | x)

#define BAD_POINTER 0xFBFBFBFBFBFBFBFB
#define MAX_ADDRESS 0xFFFFFFFFFFFFFFFF

#if defined(_MSC_VER)
#define HAVE_USED_MS_ABI 1
#elif defined(GNU_EFI_USE_MS_ABI)
#if (defined(__GNUC__) &&                                         \
     (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7))) || \
	(defined(__clang__) &&                                    \
	 (__clang_major__ > 3 ||                                  \
	  (__clang_major__ == 3 && __clang_minor__ >= 2)))
#define HAVE_USE_MS_ABI 1
#else
#error "compiler is to old to used HAVE_USE_MS_ABI"
#endif
#endif

#ifndef EFIAPI
#ifdef _MSC_EXTENSIONS
#define EFIAPI __cdecl
#elif defined(HAVE_USE_MS_ABI)
#define EFIAPI __attribute__((ms_abi))
#else
#define EFIAPI
#endif // _MSC_EXTENSIONS
#endif // EFIAPI

#endif // _EFI_BOOT_H
