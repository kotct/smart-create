#include "main.h"

#include <stdio.h>

#include <multilib/arguments.h>

#include "osdetect.h"

int main(int argc, char *argv[])
{
	printf("You are running %s\n", OS_STRING);

	ml_argument_list_t arguments = ml_arglstgen(argc, argv);

	for (int i = 0; i < argc; i++) {
		printf("%s\n", ml_argument_list_get_nth(arguments, i)->data);
	}
	
	return 0;
}
