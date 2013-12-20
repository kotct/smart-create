#include "main.h"

#include <stdbool.h>
#include <stdio.h>

#include <multilib/arguments.h>

#include "osdetect.h"
#include "touch.h"

/* Arguments */
/* -a */
bool access_time = false;
/* -c, --no-create */
bool no_create = false;
/* -d, --date= */
char *date_string;
/* -h, --no-dereference */
bool no_dereference = false;
/* -m */
bool modification_time = false;
/* -r, --reference= */
char *reference;
/* -t */
char *stamp;
/* --time= */
char *time;
/* --help */
bool help = false;
/* --version */
bool version = false;

int main(int argc, char *argv[])
{
	ml_argument_list_t arguments = ml_arglstgen(argc, argv);

	for (int i = 1; i < argc; i++) {
		touch(ml_argument_list_get_nth(arguments, i)->data);
	}

	return 0;
}
