#ifndef TOUCH_H
#define TOUCH_H

enum
{
	T_NO_A_CHANGE = 1 << 0, // don't change the access time
	T_NO_M_CHANGE = 1 << 1, // don't change the modification time
	T_NO_DEREF = 1 << 2,    // don't follow symbolic links
	T_NO_CREATE = 1 << 3    // don't create file if it doesn't exist
};

int touch(char *filename, int flags);

#endif
