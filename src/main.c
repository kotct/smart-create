#include "main.h"

#include <stdio.h>

#include <multilib/arguments.h>

#include "osdetect.h"
#include "touch.h"

int main(int argc, char *argv[])
{
	ml_argument_list_t arguments = ml_arglstgen(argc, argv);

	for (int i = 1; i < argc; i++) {
		printf("%s\n", ml_argument_list_get_nth(arguments, i)->data);
	}

	if (argc > 1) {
		touch(ml_argument_list_get_nth(arguments, 1)->data);
	}
	
	return 0;
}
