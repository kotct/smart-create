#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

#include "io.h"

fd_t io_file_open(char *filename, int flags)
{
	fd_t ret = -1;

	{
		mode_t modes = (S_IRUSR | S_IWUSR | S_IXUSR) | /* User permissions */
			(S_IRGRP | S_IWGRP | S_IXGRP) |            /* Group permissions */
			(S_IROTH | S_IWOTH | S_IXOTH);             /* Other user permissions */

		/* TODO: Add file permission modes to arguments so we have more control */
		
		ret = open(filename, flags, modes);
	}
	
	return ret;
}

int io_file_close(fd_t fd)
{
	int ret = -1;

	ret = close(fd);

	return ret;
}

fd_t io_get_fd(FILE *fstream)
{
	fd_t ret = -1;

	ret = fileno(fstream);

	return ret;
}
