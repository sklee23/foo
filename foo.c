// Copyright: 2012, John Doe.
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

//
// This comment is written in getopt branch...
// Blah blah blah...
// (Comments merged)

static char *progname;			// Holds program name.

static char *file_name;
static int dry_run;
static int unit_size = 4096;		// Default 4K
static int file_size = 1024 * 1024;	// Default 1M
static int fsync_ratio;
static int random_op_ratio;

static void print_usage(void)
{
	printf("Usage: %s [options]\n", progname);
}

static void do_test_case(void)
{
	printf("Start test...\n");
}

// This is main routine.
int main(int argc, char **argv)
{
	char c;

	progname = argv[0];
	printf ("program name: %s\n", progname);

	while ((c = getopt(argc, argv, "F:R:fxs:r:h")) != -1) {
		switch (c) {
		case 'F':
			fsync_ratio = atoi(optarg);
			break;
		case 'R':
			random_op_ratio = atoi(optarg);
			break;
		case 'f':
			file_name = optarg;
			break;
		case 'x':
			dry_run = 1;
			break;
		case 's':
			file_size = atoi(optarg);
			break;
		case 'r':
			unit_size = atoi(optarg);
			break;
		case 'h':
			// Fall through.
		default:
			print_usage();
			exit(0);
		}
	}

#if 0
	printf("optarg: %d\n", optarg);		// debug.
	printf("dry_run: %d\n", dry_run);
	printf("file_size: %d\n", file_size);
	printf("unit_size: %d\n", unit_size);
#endif

	do_test_case();

	exit(0);
}
