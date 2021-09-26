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
		int spyX;
		int spyY;
		int cameraX;
		int cameraY;
		int wallCount;
		
		scanf("%d %d %d %d %d\n", &spyX, &spyY, &cameraX, &cameraY, &wallCount);
		
		int xDelta = spyX - cameraX;
		int yDelta = spyY - cameraY;
		int isVertical = 0;
		double slope = 0.0;
		double c = 0.0;
		
		if(xDelta == 0){
			isVertical = 1;
			c = (double) spyX;
		}
		else{
			slope = (double) yDelta / (double) xDelta;
			c = spyY - (slope * spyX);
		}
		
		int intersection = 0;
		
		while(wallCount > 0){
			int startX;
			int startY;
			int endX;
			int endY;
			
			scanf("%d %d %d %d\n", &startX, &startY, &endX, &endY);
			
			int wallXDelta = endX - startX;
			int wallYDelta = endY - startY;
			int wallIsVertical = 0;
			double wallSlope = 0.0;
			double wallC = 0.0;
			
			if(wallXDelta == 0){
				wallIsVertical = 1;
				wallC = (double) startX;
			}
			else{
				wallSlope = (double) wallYDelta / (double) wallXDelta;
				wallC = startY - (wallSlope * startX);
			}
			
			if((wallIsVertical == 1 && isVertical == 1) || (wallSlope == slope)){
				// lines are parallel; do nothing
			}
			else if(wallSlope == 0.0 || slope == 0.0){
				// one line is horizontal; have to handle intersection differently
				int maxSpyX = spyX > cameraX ? spyX : cameraX;
				int minSpyX = spyX <= cameraX ? spyX : cameraX;
				int maxWallX = startX > endX ? startX : endX;
				int minWallX = startX <= endX ? startX : endX;
				double xIntersect = 0.0;
				
				if(isVertical == 1){
					xIntersect = c;
				}
				else if(wallIsVertical == 1){
					xIntersect = wallC;
				}
				else if(wallSlope == 0.0){
					xIntersect = (startY - c) / slope;
				}
				else {
					xIntersect = (spyY - wallC) / wallSlope;
				}
				
				if(maxSpyX >= xIntersect && minSpyX <= xIntersect && maxWallX >= xIntersect && minWallX <= xIntersect){
					intersection = 1;
				}
			}
			else{
				int maxSpyY = spyY > cameraY ? spyY : cameraY;
				int minSpyY = spyY <= cameraY ? spyY : cameraY;
				int maxWallY = startY > endY ? startY : endY;
				int minWallY = startY <= endY ? startY : endY;
				double yIntersect = 0.0;
				
				if(isVertical == 1){
					yIntersect = (wallSlope * spyX) + wallC;
				}
				else if(wallIsVertical == 1){
					yIntersect = (slope * startX) + c;
				}
				else{
					double slopeDelta = slope - wallSlope;
					double cDelta = wallC - c;
					double xIntersect = cDelta / slopeDelta;
					yIntersect = (slope * xIntersect) + c;
				}
				
				if(maxSpyY >= yIntersect && minSpyY <= yIntersect && maxWallY >= yIntersect && minWallY <= yIntersect){
					intersection = 1;
				}
			}
			
			wallCount = wallCount - 1;
		}
		
		if(intersection == 1){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
		
		T = T - 1;
	}
}
