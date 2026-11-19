#ifndef _IPC_NAMESPACE_H
#define _IPC_NAMESPACE_H

#include <include/defs.h>
#include <include/errno.h>
#include <stdatomic.h>

#define IPC_OPEN 0x0
#define IPC_CREAT 0x1
#define IPC_HANDOFF 0x2
#define IPC_REDIAL 0x4

struct ipc_namespace {
    sint_t id;
    key_t key;
    size_t size;
    atomic_int refcount;
    ulong_t base;
    struct shm_pages* npages;
};

struct shm_pages {
    uint_t pages;
    sint_t unpages;
    ulong_t page_addr;
    ulong_t page_vaddr;
};

#endif // _IPC_NAMESPACE_H
