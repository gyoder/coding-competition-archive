#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct Problem Problem;

int roundTo(double number);
Problem *GetTestCases(int *numOfTestCases);

struct Problem
{
	double *values;
	int count;
};

int main(void)
{
	int numCases;
	Problem *testCases = GetTestCases(&numCases);
	
	double min;
	double max;
	
	for(int i = 0; i < numCases;i++)
	{	
		min = max = testCases[i].values[0];
		for(int j = 0; j < testCases[i].count;j++)
		{
			if(testCases[i].values[j] < min)
				min = testCases[i].values[j];
			if(testCases[i].values[j] > max)
				max = testCases[i].values[j];
		}	 
		
		for(int j = 0; j < testCases[i].count;j++)
		{
			printf("%i\n",roundTo(((testCases[i].values[j] - min) / (max - min))* 255));
		}	
	}
	return 0;
}

Problem *GetTestCases(int *numOfTestCases)
{
	Problem *testCases;
	char buff[255];
	
	scanf("%s\n", buff);

	*numOfTestCases = atoi(buff);

	testCases = malloc (sizeof (Problem) * (*numOfTestCases));

	for(int i = 0; i < *numOfTestCases; i++)
	{
		scanf("%i\n",&(testCases[i].count));
		testCases[i].values = malloc (sizeof (double) * (testCases[i].count));
		for(int j = 0; j < testCases[i].count;j++)
			scanf("%lf",&testCases[i].values[j]);
	}
	
	return testCases;
}
int roundTo(double number)
{
    return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
}