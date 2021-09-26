#define __USE_XOPEN
#define _XOPEN_SOURCE
#define roundScore(x,d) ((floor(((x)*pow(10,d))+.5))/pow(10,d))

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct File File;
typedef struct Problem Problem;
typedef struct tm Time;

long round2(double number);
Problem *GetTestCases(int *numOfTestCases);
double getFileScore(File *string);
void Sort(Problem *p);

Time now;

struct File
{
	char name[255];
	double sizeInMB;
	double score;
	Time time;
};

struct Problem
{
	File *files;
	double driveSpaceInMB;
	int numOfFiles;
};

int main(void)
{
	int numCases;

	now.tm_year = 119;
	now.tm_mday = 27;
	now.tm_mon = 3; // April is 3
	now.tm_hour = 0;
	now.tm_min = 0;
	now.tm_sec = 0;

	Problem *p = GetTestCases(&numCases);

	for(int i = 0; i < numCases;i++)
	{
		bool done = false;
		int j = 0;
		double remainder = p[i].driveSpaceInMB;
		while(!done && j < p[i].numOfFiles)
		{
			if((remainder / p[i].driveSpaceInMB) >= .75)
			{
				printf("%s %.3f\n",p[i].files[j].name,roundScore(p[i].files[j].score,3));
				remainder -= p[i].files[j].sizeInMB;
			}
			else
				done = true;
			j++;
		}
	}
	return 0;
}

long round2(double number)
{
    return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
}

Problem *GetTestCases(int *numOfTestCases)
{
	Problem *testCases;
	char buff[255];

	scanf("%s", buff);

	*numOfTestCases = atoi(buff);

	testCases = malloc (sizeof (Problem) * (*numOfTestCases));

	for(int i = 0; i < *numOfTestCases; i++)
	{
		double tempSize;
		scanf("%i %lf\n",&(testCases[i].numOfFiles),&tempSize);
		testCases[i].driveSpaceInMB = round2(tempSize * 1000);
		testCases[i].files = malloc (sizeof (File) * (testCases[i].numOfFiles));
		for(int j = 0; j < testCases[i].numOfFiles;j++)
		{
			File *currentFile = &testCases[i].files[j];
			char date[30];
			char timeStr[5];
			char amOrPm[2];
			double fileSizeInKB;

			scanf("%s",date);

			// Returns first token
			char* token = strtok(date, "/");

			currentFile->time.tm_mday = atoi(token);
			token = strtok(NULL, "/");
			currentFile->time.tm_mon = atoi(token) - 1;
			token = strtok(NULL, "/");
			currentFile->time.tm_year = atoi(token) - 1900;

			scanf("%s",timeStr);

			token = strtok(timeStr, ":");
			currentFile->time.tm_hour = atoi(token);
			token = strtok(NULL, ":");
			currentFile->time.tm_min = atoi(token);
			scanf("%s",amOrPm);
			if(strcmp(amOrPm,"PM") == 0)
			{
				if(currentFile->time.tm_hour != 12)
					currentFile->time.tm_hour += 12;
			}
			else if(currentFile->time.tm_hour == 12)
				currentFile->time.tm_hour = 0;

			currentFile->time.tm_sec = 0;
			scanf(" %lf",&fileSizeInKB);
			currentFile->sizeInMB = fileSizeInKB/1000;
			scanf(" %s\n",currentFile->name);

			currentFile->score = getFileScore(currentFile);
		}
		Sort(&testCases[i]);
	}

	return testCases;
}

double getFileScore(File *file)
{
	double secondsPast;
	double daysPast;

	secondsPast = difftime(mktime(&now),mktime(&file->time));
	daysPast = secondsPast / 86400;
	if((daysPast - (int)daysPast) > .5)
		daysPast = ceil(daysPast);
	else
		daysPast = floor(daysPast) + .5;
	return daysPast * file->sizeInMB;
}

void Sort(Problem *p)
{
	for(int i = 0; i < p->numOfFiles - 1; i++)
		for(int j = 0; j < p->numOfFiles - i - 1; j++)
		{
			if(p->files[j].score < p->files[j + 1].score)
			{
				File tempFile = p->files[j];
				p->files[j] = p->files[j+1];
				p->files[j+1] = tempFile;
			}
		}
}
