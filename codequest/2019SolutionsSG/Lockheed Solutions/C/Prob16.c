#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Problem Problem;

Problem *GetTestCases(int *numOfTestCases);
int HexToInt(const char * hexString, int startIndex, int numOfChars);
char *DecodeText(const char cipherText[129], const char key[129]);

struct Problem
{
	int numKeys;
	char **keys;
	char cipherText[129];
};

int main(void)
{
	int numOfTestCases;

	Problem *testCases = GetTestCases(&numOfTestCases);

	for(int i = 0; i < numOfTestCases; i++)
		for(int j = 0; j < testCases[i].numKeys;j++)
			printf("[%s]\n",DecodeText(testCases[i].cipherText,testCases[i].keys[j]));

	// Properly free memory here (which I did not do)
	free(testCases);
}

char *DecodeText(const char cipherText[129], const char key[129])
{
	char *clearText = (char*)(malloc(sizeof(char) * 65));

	for(int i = 0; i <= 128; i += 2)
	{
		int cipherTextBinary = HexToInt(cipherText,i,2);
		int keyBinary = HexToInt(key,i,2);
		clearText[i/2] = (char) (cipherTextBinary ^ keyBinary);
	}
	return clearText;
}

int HexToInt(const char * hexString, int startIndex, int numOfChars)
{
	char *subString = malloc (sizeof(char) * numOfChars  + 1);
	subString = strncpy(subString, hexString + startIndex, numOfChars);
	*(subString + numOfChars) = '\0';    // Have to add the null term char
	int num = (int)strtol(subString, NULL, 16);

	return num;
}

Problem *GetTestCases(int *numOfTestCases)
{
	Problem *testCases;
	char buff[255];
	
	scanf("%s", buff);

	*numOfTestCases = atoi(buff);

	testCases = (Problem*)(malloc (sizeof (Problem) * (*numOfTestCases)));

	for(int i = 0; i < *numOfTestCases; i++)
	{
		scanf("%i\n", &testCases[i].numKeys);
		scanf("%s\n", testCases[i].cipherText);
		testCases[i].keys = (char**)(malloc (sizeof (char*) * (testCases[i].numKeys)));
		for(int j = 0 ;j < testCases[i].numKeys;j++)
		{
			testCases[i].keys[j] = (char*)(malloc (sizeof (char) * 129));
			scanf("%s\n", testCases[i].keys[j]);
		}
	}

	return testCases;
}
