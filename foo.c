#include <stdio.h>
#include <stdlib.h>

static char *progname;			// Holds program name.

// This is main routine.
int main(int argc, char **argv)
{
	progname = argv[0];

	printf("Program name: %s\n", progname);

	exit(0);
}
