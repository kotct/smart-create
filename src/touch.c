#include "touch.h"

#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#include <multilib/io.h>

int touch(char *filename, int flags) {
	ml_fd_t fd;
	int open_flags = O_RDWR | (flags & T_NO_DEREF ? O_NOLINK : 0) | (flags & T_NO_CREATE ? 0 : O_CREAT);
	// note: on the following line, the mode appears to be ignored, even when creating a new file.
	// I'm not sure why this is, but it doesn't really matter.
	if (fd = ml_iofopen(filename, open_flags, ml_iostr2mod("rw-rw-rw-")) == -1) {
		fprintf(stderr, "ERROR! STOP!\n");
		return -1;
	}
	{
		struct stat stat;
		timespec times[2];
		if (stat(filename, &stat) != 0) {
			fprintf(stderr, "WATZ?\n");
			return -1;
		}

		if (flags & T_NO_A_CHANGE) times[0] =  stat.st_atime;
		else clock_gettime(CLOCK_REALTIME, &times[0]);

		if (flags & T_NO_M_CHANGE) times[1] =  stat.st_atime;
		else clock_gettime(CLOCK_REALTIME, &times[1]);

		futimes(fd, times);
	}
	ml_iofclose(fd);
}



