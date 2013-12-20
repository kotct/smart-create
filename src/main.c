#include "main.h"

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

int main(int argc, char *argv[])
{
	/* Create arguments and files to be made list. */
	ml_argument_list_t arguments = ml_arglstgen(argc, argv);

	/* Remove program name. */
	arguments = ml_ldnth(arguments, 0);

	/* Scan arguments for command-line arguments. */
	/* ml_lsrch should be renamed to ml_arglsrch. */
	if (ml_lgnn(ml_lsrch(arguments, "-a")) > 0) {
		access_time = true;

		for (size_t i = 0; i < ml_lgnn(ml_lsrch(arguments, "-a")); i++)
			arguments = ml_ldnth(arguments, i);
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
	for (size_t i = 0; i < ml_lgnn(arguments); i++) {
		touch(ml_arglstgnth(arguments, i)->data);
	}

	return 0;
}
