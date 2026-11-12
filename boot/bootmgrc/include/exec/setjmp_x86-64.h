#ifndef _SETJMP_X86_64_H
#define _SETJMP_X86_64_H

#define EFI_SETJUMP_BUFFER 8

typedef struct {
	uint64_t rbx;
	uint64_t rbp;
	uint64_t rsi;
	uint64_t rdi;
	uint64_t rip;
	uint64_t mxcsr;
	uint8_t xmm[16][16];

	uint64_t r12;
	uint64_t r13;
	uint64_t r14;
	uint64_t r15;
	uint64_t rsp;
} EFI_ALIGN(EFI_SETJUMP_BUFFER) jmp_buf[1];

#endif
