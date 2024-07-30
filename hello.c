/***************************************
 * SPDX-License-Identifier: MIT
 *
 * hello.c - print "Hello World" and simulate test execution
 * This is for example, and for testing test systems
 *
 * Copyright 2016 Sony Corporation
 * Author: Tim Bird <tim.bird@am.sony.com
 ***************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void usage(void)
{
	printf("Usage: hello [-h|-f|-r]\n\n");
	printf("Print \"Hello world\", and show a testing result.\n");
	printf("Options:\n");
	printf(" -h   Show this test usage\n");
	printf(" -f   Force the test to fail\n");
	printf(" -r   Randomaly have the test succeed or fail\n");
	printf("      The test should succeed (and fail) about 50%% of the time\n"); }

int randint(int bottom, int top)
{
	int range;

	range = (top - bottom) + 1;
	return(rand() % range) + bottom;
}

int main(int argc, char **argv)
{
	int failtest;

	printf("Hello World!\n\n");

	printf("This is a test program, to demonstrate test success and failure\n");

	// check arguments, and simulate test execution
	failtest = 0;
	if (argc >= 2) {
		if (strcmp(argv[1], "-h")==0 ||
		    strcmp(argv[1], "--help")==0 ) {
			usage();
			exit(0);
		}
		if (strcmp(argv[1], "-f")==0) {
			failtest = 1;
		}
		if (strcmp(argv[1], "-r")==0) {
			srand(time(NULL));
			if (randint(1,10)<=5) {
				failtest = 1;
			}
		}
	}
	
	// show "test" results
	printf("Test result: ");
	if (failtest) {
		printf("FAIL\n");
	} else {
		printf("SUCCESS\n");
	}
	return 0;
}
