#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int randint(int bottom, int top)
{
	int range;

	range = (top - bottom) + 1;
	return(rand() % range) + bottom;
}

int main(int argc, char **argv)
{
	printf("hello-test says Hello!\n");

	srand(time(NULL));
	if (randint(1,10)<=5) {
		printf("status: OK!\n");
		return 0;
	} else {
		printf("status: Failure!\n");
		return -1;
	}
}
