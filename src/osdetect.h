#ifndef OSDETECT_H
#define OSDETECT_H

/*
 * osdetect.h
 *
 * Detects which OS the program is running on.
 *
 * Macros to use
 * OS_INT - integer assigned to various OSes, good for logic.
 * OS_STRING - string assigned to various OSes, good for users to read.
 * PATH_SEP - string used to separate directories in paths.
 */

/* The integers associated with various OSes. */
#define WINDOWS_INT 0
#define LINUX_INT 1
#define MAC_INT 2
#define UNDEF_INT -1

/* The strings associated with various OSes. */
#define WINDOWS_STRING "Windows"
#define MAC_OS_STRING "Mac OS"
#define LINUX_STRING "Linux"
#define UNDEF_STRING "undef"

/*
 * See if OS-identifying macros are defined.
 * If so, define OS_INT and OS_STRING to their correct OS values.
 */
#ifdef _WIN64
#define OS_INT WINDOWS_INT
#define OS_STRING WINDOWS_STRING
#elif _WIN32
#define OS_INT WINDOWS_INT
#define OS_STRING WINDOWS_STRING
#elif __APPLE__
#define OS_INT MAC_INT
#define OS_STRING MAC_OS_STRING
#elif __linux
#define OS_INT LINUX_INT
#define OS_STRING LINUX_STRING
#elif __unix
#define OS_INT LINUX_INT
#define OS_STRING LINUX_STRING
#elif __posix
#define OS_INT LINUX_INT
#define OS_STRING LINUX_STRING
#else
#define OS_INT UNDEF_INT
#define OS_STRING UNDEF_STRING
#endif

/*
 * Set PATH_SEP to a string that is used to separate directories.
 * It could function as a character, but that breaks strcat.
 */
#if OS_INT == WINDOWS_INT
#define PATH_SEP "\\"
#else
#define PATH_SEP "/"
#endif

#endif
