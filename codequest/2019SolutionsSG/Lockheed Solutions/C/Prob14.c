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
		int passes;
		scanf("%d\n", &passes);
		
		char departures[passes][100];
		char arrivals[passes][100];
		
		int i = 0;
		
		while(i < passes){			
			scanf("%s %s\n", departures[i], arrivals[i]);
						
			i = i + 1;
		}
		
		char* currentCity;
		int currentCityIndex = -1;
		i = 0;
		
		// find the final destination
		while(i < passes){
			char* city = arrivals[i];
			
			int j = 0;
			int found = 0;
			while(j < passes){
				if(strcmp(city, departures[j]) == 0){
					found = 1;
					break;
				}
				j = j + 1;
			}
			
			if(found == 0){
				currentCity = city;
				currentCityIndex = i;
				break;
			}
			
			i = i + 1;
		}
		
		printf("%s\n", currentCity);
		
		// find the next destination until we run out
		int visited = 0;
		while(visited < passes){
			currentCity = departures[currentCityIndex];
			printf("%s\n", currentCity);
			
			i = 0;
			
			while(i < passes){
				if(strcmp(currentCity, arrivals[i]) == 0){
					currentCityIndex = i;
					break;
				}
				i = i + 1;
			}
			
			visited = visited + 1;
		}

		T = T - 1;
	}
}
