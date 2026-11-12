#ifndef _INODE_H
#define _INODE_H

#include <defs.h>

#define NADDR 13

struct inode {
	sshort_t flags;
	uchar_t count; // referense of count
	schar_t fs_type; // the type of filesystems
	dev_t dev; // device where in resides
	slong_t number; // number, from 1-to-1 with a drivers
	ushort_t mode;
	ushort_t nlink; // directory entries
	sshort_t uid; // owner
	sshort_t gid; // group of owner
	size_t size;
	struct inode *mroot; // mount point of root inode
	struct inode *mpoint; // inode of mount point
	union {
		struct {
			daddr_t addr[NADDR]; // if a normal directory/file
			daddr_t last_read; // last read (for read-ahead)
			struct buf *bufp; // buffer for supper-block
		} f;
		struct {
			daddr_t rdev;
			slong_t key;
		} d;
		struct {
			slong_t tag;
			struct inode *cip; /* communications */
		} a; /* when fstyp != 0 */
	} i_un;
	struct inode *hlink; // link in hash chain (get/put/find)
};

#endif // _INODE_H
