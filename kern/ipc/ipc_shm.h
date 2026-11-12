#ifndef _IPC_SHM_H
#define _IPC_SHM_H

#include <../include/defs.h>

#include "ipc_namespace.h"
#include "util.h"

#define IPC_OPEN 0x0
#define IPC_CREAT 0x1
#define IPC_HANDOFF 0x2
#define IPC_CAREFULL 0x4
#define IPC_REDIAL 0x8

#define SHM_FLAGS	 32
#define SHM_MEMORY_DATA	 0x0000001
#define SHM_VIRTUAL_DATA 0x0000002

struct shm_attach {
  uintptr_t vaddr;
  size_t size;
  uint_t prot;
  struct shm_segment *seg;
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
  struct ipc_namespace *next;
  struct list_head link;
};

struct shm_table {
  sint_t next_id;
  spinlock_t lock;
  struct shm_segment *by_str;
  struct list_head head;
};

static inline sint_t
shmget(key_t key, size_t size, int flags)
{
  int id;

	if (key == id) {
		return id;
	} else {
		return key + IPC_CREAT;
	}
}

static inline sint_t
shmat(int id, ulong_t addr, int flags)
{
  struct shm_segment *seg;
  
  while (seg->key) {
    if (id == seg->key) {
       
    }
  }
}

#endif // _IPC_SHM_H
