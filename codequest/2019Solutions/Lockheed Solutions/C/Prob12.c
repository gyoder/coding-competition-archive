// Recommended includes for all problems. Some problems
// may require additional libraries.
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int T;

	// get the number of test cases
	scanf("%d\n", &T);

	// loop through the test cases
	while (T > 0)
	{
		int doors;
		int rounds;
		int open;
		scanf("%d %d %d\n", &doors, &rounds, &open);
		
		float maxProbability = 100.0 / doors;
		int unselectedOpenDoors = doors - 1;
		
		while(rounds > 0){
			// open doors
			float opened = maxProbability * open;
			unselectedOpenDoors = unselectedOpenDoors - open;
			// distribute probability to remaining doors
			maxProbability = maxProbability + (opened / unselectedOpenDoors);
			// select new door
			unselectedOpenDoors = unselectedOpenDoors - 1;
			
			rounds = rounds - 1;
		}
		
		// round it off
		float multiplied = maxProbability * 100.0;
		float floored = floor(multiplied);
		float remainder = multiplied - floored;
		if(remainder > 0.5){
			floored = floored + 1;
		}
		maxProbability = floored / 100.0;
		
		printf("%0.2f%%\n", maxProbability);

		T = T - 1;
	}
}
