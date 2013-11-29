#ifndef IO_H
#define IO_H

/* Handy typedefs */
typedef int file_descriptor_t;
typedef file_descriptor_t fd_t;

fd_t io_file_open(char *filename, int flags);
int io_file_close(fd_t fd);

#endif
