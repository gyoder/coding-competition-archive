// Recommended includes for all problems. Some problems
// may require additional libraries.
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int T;
	const int letterConversion = 96;

	// get the number of test cases
	scanf("%d\n", &T);

	// loop through the test cases
	while (T > 0)
	{
		char valuesLine[1024];
		long timestamps[10];
		
		fgets(valuesLine, 1024, stdin);
		scanf("%ld %ld %ld %ld %ld %ld %ld %ld %ld %ld\n", &timestamps[0], &timestamps[1], &timestamps[2], &timestamps[3], 
			&timestamps[4], &timestamps[5], &timestamps[6], &timestamps[7], &timestamps[8], &timestamps[9]);
			
		int timestampIndex = 0;
		int wordValue = 0;
		int valuesIndex = 0;
		double previousHash = 0;
		
		do {
			char nextChar = valuesLine[valuesIndex];
			
			if(nextChar == ' '){
				// word break
				previousHash = ((timestamps[timestampIndex] + wordValue + timestampIndex + 1 + previousHash) * 50.0) / 147.0;
				wordValue = 0;
				timestampIndex = timestampIndex + 1;
			}
			else{
				int letterValue = (int) nextChar - letterConversion;
				wordValue = wordValue + letterValue;
			}
			
			valuesIndex = valuesIndex + 1;
		} while(valuesLine[valuesIndex] != '\0' && valuesLine[valuesIndex] != '\r' && valuesLine[valuesIndex] != '\n');
		
		// calculate final hash
		previousHash = ((timestamps[timestampIndex] + wordValue + timestampIndex + 1 + previousHash) * 50.0) / 147.0;
		
		double floored = floor(previousHash);
		double remainder = previousHash - floored;
		if(remainder > 0.5){
			floored = floored + 1;
		}
		long resultHash = (long) floored;
		
		printf("%ld\n", resultHash);

		T = T - 1;
	}
}
