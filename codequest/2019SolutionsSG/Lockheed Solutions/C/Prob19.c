#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Problem Problem;

unsigned int Ip_to_Int (const char * ip);
char *Int_to_Ip(unsigned int intIP);
Problem *GetTestCases(int *numOfTestCases);

struct Problem
{
	char **ips;
	int numOfIps;
};

int main(void)
{
	int numOfTestCases;
	Problem *p = GetTestCases(&numOfTestCases);

	for(int i = 0; i < numOfTestCases; i++)
	{
		unsigned int lastGoodMask = 0;   // The last mask which all IPs fit in
		int lastGoodCidr = 0;		     // Same as above but the CIDR
		for(int j = 1; j <= 32;j++)
		{
			unsigned int mask;
		    mask = 0xFFFFFFFF << (32 - j);
		    unsigned int subnet = Ip_to_Int(p[i].ips[0]) & mask;
			bool foundSubnet = true;
			for(int k = 1; k < p[i].numOfIps; k++)
			{
				if(subnet != (Ip_to_Int(p[i].ips[k]) & mask))
				{
					foundSubnet = false;
					break;
				}
			}
			if(j == 32 && foundSubnet == true) // Silly hack to handle the edge case where all the IPs are the same
			{
				lastGoodCidr++;
				foundSubnet = false;   // Set to false so we'll print the output
			}
			if(foundSubnet == false)
			{
				printf("%s/%d\n",Int_to_Ip(Ip_to_Int(p[i].ips[0]) & lastGoodMask),lastGoodCidr);
				break;
			}
			else
			{
				lastGoodMask = mask;
				lastGoodCidr = j;
			}
		}
	}
}

unsigned int Ip_to_Int (const char * ip)
{
    unsigned v = 0;
    int i;
    const char * start;

    start = ip;
    for (i = 0; i < 4; i++)
    {
        char c;
        int n = 0;
        while (true)
        {
            c = *start;
            start++;
            if (c >= '0' && c <= '9')
            {
                n *= 10;
                n += c - '0';
            }
            else if ((i < 3 && c == '.') || i == 3)
            	break;
            else
            	return 0;
        }
        if (n >= 256)
            return 0;
        v *= 256;
        v += n;
    }
    return v;
}
char *Int_to_Ip(unsigned int intIP)
{
	char aStr[4], bStr[4], cStr[4], dStr[4];
	char *finalStr = malloc (sizeof (char) * 16);
	unsigned short a,b,c,d;

	// Convert each octet to a string then concat them all together and return the final string
	a = (intIP & (0xff << 24)) >> 24;
	sprintf(aStr, "%d", a);
	strcpy(finalStr,aStr);
	strcat(finalStr,".");
	b = (intIP & (0xff << 16)) >> 16;
	sprintf(bStr, "%d", b);
	strcat(finalStr,bStr);
	strcat(finalStr,".");
	c = (intIP & (0xff << 8)) >> 8;
	sprintf(cStr, "%d", c);
	strcat(finalStr,cStr);
	strcat(finalStr,".");
	d = intIP & 0xff;
	sprintf(dStr, "%d", d);
	strcat(finalStr,dStr);

	return finalStr;
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
		scanf("%d\n",&(testCases[i].numOfIps));
		testCases[i].ips = (char**)(malloc (sizeof (char*) * (testCases[i].numOfIps)));
		for(int j = 0; j < testCases[i].numOfIps;j++)
		{
			testCases[i].ips[j] = (char*)malloc (sizeof (char) * 15);
			scanf("%s\n",testCases[i].ips[j]);
		}
	}
		
	return testCases;
}
