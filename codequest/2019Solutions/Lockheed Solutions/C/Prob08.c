#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Problem Problem;

Problem *GetTestCases(int *numOfTestCases);
void FillGrid(int grid[20][20], int row, int col, int setValue);
void ZeroOutGrid(int grid[20][20]);
void PrintGrid(int grid[20][20]);

struct Problem
{
	int row;
	int col;
	int grid[20][20];
};

int main(void)
{
	int numOfTestCases;

	Problem *testCases = GetTestCases(&numOfTestCases);

	for(int i = 0; i < numOfTestCases; i++)
	{
		ZeroOutGrid(testCases[i].grid);
		FillGrid(testCases[i].grid,testCases[i].row,testCases[i].col, 100);
		PrintGrid(testCases[i].grid);
		printf("\n");
	}

	// Properly free memory here (which I did not do)
	free(testCases);
}

void FillGrid(int grid[20][20], int row, int col, int setValue)
{
	if(row >= 0 && col >= 0 && row <= 19 && col <= 19)
	{
		if(grid[row][col] < setValue)
		{
			grid[row][col] = setValue;

			switch(setValue)
			{
				case 100:
					setValue = 50;
					break;
				case 50:
					setValue = 25;
					break;
				default:
					setValue = 10;
					break;
			}

			for(int i = -1; i < 2; i++)
				for(int j = -1; j < 2; j++)
					FillGrid(grid,row + i, col + j,setValue);
		}
	}
}

void ZeroOutGrid(int grid[20][20])
{
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < 20; j++)
			grid[i][j] = 0;
}

void PrintGrid(int grid[20][20])
{
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			printf("%i", grid[i][j]);
			if(j != 19)
				printf(" ");
		}
		if(i != 19)
			printf("\n");
	}
}

Problem *GetTestCases(int *numOfTestCases)
{
	Problem *testCases;
	char buff[255];
	
	scanf("%s", buff);

	*numOfTestCases = atoi(buff);

	testCases = (Problem*)(malloc (sizeof (Problem) * (*numOfTestCases)));

	for(int i = 0; i < *numOfTestCases; i++)
		scanf("%i %i\n", &testCases[i].row,&testCases[i].col);

	return testCases;
}
