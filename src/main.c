#include "main.h"

#include <getopt.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#include <multilib/arguments.h>

#include "touch.h"

#define VERSION_NUMBER "0.0.1"
#define VERSION_SENTENCE "Smart Create v"VERSION_NUMBER"\n"
#define VERSION_PARAGRAPH	\
	VERSION_SENTENCE \
	"Copyright (C) 2013 Sam Craig, Kristofer Rye, Christopher Cooper\n" \
	"License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.\n" \
	"This is free software: you are free to change and redistribute it.\n" \
	"There is NO WARRANTY, to the extent permitted by law."

/* Arguments */
/* -a */
bool access_time = false;
/* -c, --no-create */
bool no_create = false;
/* -d, --date= */
char *date_string = NULL;
/* -h, --no-dereference */
bool no_dereference = false;
/* -m */
bool modification_time = false;
/* -r, --reference= */
char *reference = NULL;
/* -t */
char *stamp = NULL;
/* --time= */
char *time = NULL;
/* --help */
bool help = false;
/* --version */
bool version = false;

/*
 * Enums of long options that do not have short options.
 * In order to avoid having a short option, a non-character must be provided.
 */
enum {
	TIME_OPTION = CHAR_MAX + 1,
	HELP_OPTION,
	VERSION_OPTION
};

/* Valid arguments for '--time' option. */
const char *time_args[] =
{
	"atime", "access", "use", "mtime", "modify", NULL
};

/* Argument data. */
const struct option longopts[] =
{
	{"time", required_argument, NULL, TIME_OPTION},
	{"no-create", no_argument, NULL, 'c'},
	{"date", required_argument, NULL, 'd'},
	{"reference", required_argument, NULL, 'r'},
	{"no-dereference", no_argument, NULL, 'h'},
	{"help", no_argument, NULL, HELP_OPTION},
	{"version", no_argument, NULL, VERSION_OPTION},
	{NULL, 0, NULL, 0}
};

int main(int argc, char *argv[])
{
	int c;
	while ((c = getopt_long(argc, argv, "acd:fhmr:t:", longopts, NULL)) != -1) {
		switch (c) {
		case 'a':
			break;
		case 'c':
			break;
		case 'd':
			break;
		case 'f':
			break;
		case 'h':
			break;
		case 'm':
			break;
		case 'r':
			break;
		case 't':
			break;
		case TIME_OPTION:
			break;
		case HELP_OPTION:
			break;
		case VERSION_OPTION:
			break;
		default:
			break;
		}
	}

	/*
	 * Check if help or version is true.
	 * If so, exit before creating files.
	 */
	if (help || version) {
		if (help) {
			printf("%s\n", VERSION_SENTENCE);
			
			printf("Help strings.\n");
		}

		if (help && version)
			printf("\n");

		if (version)
			printf("%s\n", VERSION_PARAGRAPH);
		
		exit(0);
	}

	/* Create the files that must be made. */
	for (int index = optind; index < argc; index++) {
		touch(argv[index]);
	}

	return 0;
}
