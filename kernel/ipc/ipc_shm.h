#ifndef _IPC_SHM_H
#define _IPC_SHM_H

#include "ipc_namespace.h"
#include "util.h"

#include <include/defs.h>

#define SHM_FLAGS 32
#define SHM_MEMORY_DATA 0x0000001
#define SHM_VIRTUAL_DATA 0x0000002

struct shm_attach {
    uintptr_t vaddr; // Virtual address memory
    uintptr_t paddr; // Physicall address memory
    size_t size;
    uint_t prot;
    struct shm_segment* seg;
    struct list_head link;
};

struct shm_segment {
    slong_t id;
    key_t key;
    size_t size;
    uint_t unpages;
    uint_t mode;
    uint_t gid;
    bool deleted;
    spinlock_t lock;
    struct ipc_namespace* next;
    struct list_head link;
    struct shm_pages* npages;
};

struct shm_table {
    sint_t next_id;
    spinlock_t lock;
    struct shm_segment* by_str;
    struct list_head head;
};

static void *shmget(key_t key, size_t size, sint_t flags);
static void *shmat(sint_t id, slong_t addr, sint_t flags);
static void *shmmap(ulong_t addr, key_t mapkey, sint_t flags);

#endif // _IPC_SHM_H
