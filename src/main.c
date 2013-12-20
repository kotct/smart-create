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


int main(int argc, char *argv[])
{
	ml_argument_list_t arguments = ml_arglstgen(argc, argv);

	for (int i = 1; i < argc; i++) {
		printf("%s\n", ml_argument_list_get_nth(arguments, i)->data);
	}
	
	return 0;
}
