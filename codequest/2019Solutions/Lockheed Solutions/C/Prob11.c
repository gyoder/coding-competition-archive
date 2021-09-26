#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int * GetTestCases(int *numOfTestCases);

int main(void)
{
	int *testCases;
	int numOfTestCases = 0;
	int c, d, count;
    char *pointer;

	testCases = GetTestCases(&numOfTestCases);

	for(int i = 0; i < numOfTestCases; i++)
	{
		int numOfBits = testCases[i];

		for (int j = 0; j < pow(2,numOfBits); j++)
		{
			if(j != 0)
				printf("\n");
			count  = 0;
			pointer = (char*)malloc(32+1);
			for (c = numOfBits - 1 ; c >= 0 ; c--)
			{
				d = j >> c;
				if (d & 1)
					pointer[count] = 1 + '0';
				else
					pointer[count] = 0 + '0';

				count++;
			}
			pointer[count] = '\0';
			printf("%s",pointer);
		}
		
		printf("\n");
	}
	free(testCases);
}

int * GetTestCases(int *numOfTestCases)
{
	int *testCases;
	char buff[255];
	
	scanf("%s", buff);

	*numOfTestCases = atoi(buff);//*buff - '0';

	testCases = (int*)(malloc (sizeof (int) * (*numOfTestCases)));

	int i = 0;
	while(scanf("%d", buff) != EOF)
		testCases[i++] = *buff;

	return testCases;
}
