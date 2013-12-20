#include "touch.h"

#include <stdio.h>
#include <sys/time.h>

#include <multilib/io.h>

int touch(char *filename) {
	// note: on the following line, the mode appears to be ignored, even when creating a new file.
	// I'm not sure why this is, but it doesn't really matter.
	ml_fd_t fd = ml_iofopen(filename, O_RDWR | O_CREAT | O_APPEND, ml_iostr2mod("rw-rw-rw-"));
	if (futimes(fd, NULL) != 0) {
		fprintf(stderr, "We errored :(\n");
	}
	ml_iofclose(fd);
}
