#ifndef _IPC_NAMESPACE_H
#define _IPC_NAMESPACE_H

#include <stdatomic.h>
#include <include/defs.h>
#include <include/errno.h>

struct ipc_namespace {
	sint_t id;
	key_t key;
	size_t size;
	atomic_int refcount;
};

struct shm_pages {

};

#endif // _IPC_NAMESPACE_H
