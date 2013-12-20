#include "main.h"

#include <stdbool.h>
#include <stdio.h>

#include <multilib/arguments.h>

#include "osdetect.h"
#include "touch.h"

#define VERSION "0.0.1"

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

int main(int argc, char *argv[])
{
	/* Create arguments and files to be made list. */
	ml_argument_list_t arguments = ml_arglstgen(argc, argv);
	ml_list_t *files_to_be_made = NULL;

	/* Scan arguments, add arguments to files_to_be_made. */
	for (int i = 1; i < argc; i++) {
		char *argument_data = ml_arglstgnth(arguments, i)->data;
		
		if (argument_data[0] != '-')
			files_to_be_made = ml_lnnew(files_to_be_made, argument_data);
	}

	/*
	 * Check if help or version is true.
	 * If so, exit before creating files.
	 */
	if (help || version) {
		if (help)
			printf("Help strings.\n");

		if (help && version)
			printf("\n");

		if (version)
			printf("%s\n", VERSION)
		
		exit(0);
	}

	/* Create the files that must be made. */
	for (size_t i = 0; i < ml_lgnn(files_to_be_made); i++) {
		touch(ml_lngdat(ml_lgnth(files_to_be_made, i)));
	}

	return 0;
}
