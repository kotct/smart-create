#include "main.h"

#include <stdio.h>

#include <multilib/arguments.h>

#include "osdetect.h"

int main(int argc, char *argv[])
{
	printf("You are running %s\n", OS_STRING);
	
	return 0;
}
