// Recommended includes for all problems. Some problems
// may require additional libraries.
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int T;
	char text[1024];

	// get the number of test cases
	scanf("%d\n", &T);

	// loop through the test cases
	while (T > 0)
	{
		// read and reprint each line
		fgets(text, 1024, stdin);
		printf(text);

		T = T - 1;
	}
}
