#ifndef _KERNEL_DEF_H
#define _KERNEL_DEF_H

#include <stdalign.h>
#include <stdnoreturn.h>
#include <stdatomic.h>

#ifndef __ASSEMBLY__

/* ====== data type kernel ====== */
typedef unsigned long long ulong_t; // 64-bit unsigned 0-63
typedef signed long long slong_t; // 64-bit signed 32-0-31
typedef unsigned int uint_t; // 32-bit unsigned 0-31
typedef signed int sint_t; // 32-bit signed 16-0-15
typedef unsigned short ushort_t; // 16-bit unsigned 0-15
typedef signed short sshort_t; // 16-bit signed 8-0-7
typedef unsigned char uchar_t; // 8-bit unsigned 0-7
typedef signed char schar_t; // 8-bit signed 4-0-3

#ifndef __SIZE_T__
#define __SIZE_T__
typedef __SIZE_TYPE__ size_t;
#endif

#ifndef __PTRDIFF_T__
#define __PTRDIFF_T__
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#endif

#ifndef __INTPTR_T__
#define __INTPTR_T__
typedef __INTPTR_TYPE__ intprt_t;
#endif

#ifndef __UINTPTR_T__
#define __UINTPTR_T__
typedef __UINTPTR_TYPE__ uintptr_t;
#endif

#ifndef nullptr
#define nullptr ((void *)0)
#endif

#ifdef BOOLEAN
#define bool _Bool
#define true 1
#define false 0
#endif

/* ====== data type for module of kernel ====== */
typedef ulong_t daddr_t; // Disk address
typedef uint_t vaddr_t;
typedef uchar_t *caddr_t; // core address
typedef uint_t fflags_t; // file flags
typedef uint_t ino_t;
typedef uint_t times_t;
typedef uint_t label_t[8];
typedef uint_t dev_t;
typedef uint_t off_t;
typedef ulong_t nlink_t; // link count
typedef slong_t key_t; // IPC key to access user_mode and kernel_mode
typedef ushort_t mode_t; // premission
typedef uint_t accmode_t; // access premission
typedef uint_t spinlock_t;
typedef ulong_t rlim_t; /* resource limit - intentionally
                         * signed, because of legacy code 
                         * that uses -1 for RLIM_INFINITY */
typedef sint_t id_t; // can hold a gid_t, pid_t, or uid_t
typedef uint_t gid_t;
typedef sint_t pid_t; // process [group]
typedef uint_t uid_t;

struct list_head {
	struct list_head *next, **prev;
	struct list_node *first;
};

struct list_node {
	struct list_node *next, **prev;
};

struct ustat {
	daddr_t f_free;
#ifdef CONFIG_ARCH_32_F_INODE_USTAT
	uint_t f_inode;
#else
	ulong_t f_inode;
#endif
	schar_t f_name[6];
	schar_t f_pack[6];
};

struct callback_head {
	struct callback_head *next;
	void (*func)(struct callback_head *head);
} __attribute__((aligned(sizeof(void *))));

#endif // __ASSEMBLY__

void *callback_kernel(uint_t *call, size_t size);

#endif // _KERNEL_DEF_H
