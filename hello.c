/***************************************
 * hello.c - print "Hello World" and simulate test execution
 * This is for example, and for testing test systems
 *
 * Copyright 2016 Sony Corporation
 * Author: Tim Bird <tim.bird@am.sony.com
 * License: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
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
		return -1;
	} else {
		printf("SUCCESS\n");
		return 0;
	}
}
