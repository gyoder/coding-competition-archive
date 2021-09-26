// Recommended includes for all problems. Some problems
// may require additional libraries.
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
// added for this problem
#include <list>
using namespace std;

const int WALL = -1;
const int EXIT = 0;
const int UNSET = -2;

struct Point {
	int x;
	int y;
};

int main()
{
	int testCases;
	cin >> testCases;
	string dummy;
	getline(cin, dummy);
	
	for(int testcase = 0; testcase < testCases; testcase++){
		int width, height;
		cin >> width >> height;
		getline(cin, dummy);
		
		string map[height];
		int weights[height][width];
		Point destinations[height][width];
		
		for(int i = 0; i < height; i++){
			getline(cin, map[i]);
		}
		
		Point startPoint;
		list<Point> activePoints = {};
		
		// initialize maps
		for(int y = 0; y < height; y++){
			for(int x = 0; x < map[y].length(); x++){
				if(map[y][x] == '#'){
					weights[y][x] = WALL;
				}
				else if(map[y][x] == 'X'){
					weights[y][x] = EXIT;
					Point exitPoint;
					exitPoint.x = x;
					exitPoint.y = y;
					activePoints.push_back(exitPoint);
					destinations[y][x] = exitPoint;
				}
				else if(map[y][x] == 'o'){
					weights[y][x] = UNSET;
					startPoint.x = x;
					startPoint.y = y;
				}
				else{
					weights[y][x] = UNSET;
				}
			}
		}
				
		// fill in weights map until we find the start point
		while(true){
			Point point = activePoints.front();
			int pointValue = weights[point.y][point.x];
			Point destination = destinations[point.y][point.x];
			
			if(point.x != 0 && weights[point.y][point.x - 1] == UNSET){
				weights[point.y][point.x - 1] = pointValue + 1;
				destinations[point.y][point.x - 1] = destination;
				Point newPoint;
				newPoint.x = point.x - 1;
				newPoint.y = point.y;
				activePoints.push_back(newPoint);
				
				if(newPoint.x == startPoint.x && newPoint.y == startPoint.y){
					break;
				}
			}
			if(point.y != 0 && weights[point.y - 1][point.x] == UNSET){
				weights[point.y - 1][point.x] = pointValue + 1;
				destinations[point.y - 1][point.x] = destination;
				Point newPoint;
				newPoint.x = point.x;
				newPoint.y = point.y - 1;
				activePoints.push_back(newPoint);
				
				if(newPoint.x == startPoint.x && newPoint.y == startPoint.y){
					break;
				}
			}
			if(point.x + 1 != width && weights[point.y][point.x + 1] == UNSET){
				weights[point.y][point.x + 1] = pointValue + 1;
				destinations[point.y][point.x + 1] = destination;
				Point newPoint;
				newPoint.x = point.x + 1;
				newPoint.y = point.y;
				activePoints.push_back(newPoint);
				
				if(newPoint.x == startPoint.x && newPoint.y == startPoint.y){
					break;
				}
			}
			if(point.y + 1 != height && weights[point.y + 1][point.x] == UNSET){
				weights[point.y + 1][point.x] = pointValue + 1;
				destinations[point.y + 1][point.x] = destination;
				Point newPoint;
				newPoint.x = point.x;
				newPoint.y = point.y + 1;
				activePoints.push_back(newPoint);
				
				if(newPoint.x == startPoint.x && newPoint.y == startPoint.y){
					break;
				}
				
			}
			
			activePoints.pop_front();
		}
		
		activePoints.clear();
		
		int currentWeight = weights[startPoint.y][startPoint.x];
		Point currentPoint;
		currentPoint.x = startPoint.x;
		currentPoint.y = startPoint.y;
		
		// fill in the path using the weights map
		while(currentWeight > EXIT){
			if(map[currentPoint.y][currentPoint.x] != 'o'){
				map[currentPoint.y][currentPoint.x] = '.';
			}
			
			currentWeight--;
			string direction = "none";
			Point destination;
			
			if(currentPoint.x != 0 && weights[currentPoint.y][currentPoint.x - 1] == currentWeight){
				direction = "left";
				destination = destinations[currentPoint.y][currentPoint.x - 1];
			}
			if(currentPoint.y != 0 && weights[currentPoint.y - 1][currentPoint.x] == currentWeight){
				Point otherDestination = destinations[currentPoint.y - 1][currentPoint.x];
				if(direction == "none" || otherDestination.x + otherDestination.y < destination.x + destination.y){					
					direction = "up";
					destination = otherDestination;
				}
			}
			if(currentPoint.x + 1 != width && weights[currentPoint.y][currentPoint.x + 1] == currentWeight){
				Point otherDestination = destinations[currentPoint.y][currentPoint.x + 1];
				if(direction == "none" || otherDestination.x + otherDestination.y < destination.x + destination.y){					
					direction = "right";
					destination = otherDestination;
				}
			}
			if(currentPoint.y + 1 != height && weights[currentPoint.y + 1][currentPoint.x] == currentWeight){
				Point otherDestination = destinations[currentPoint.y + 1][currentPoint.x];
				if(direction == "none" || otherDestination.x + otherDestination.y < destination.x + destination.y){					
					direction = "down";
					destination = otherDestination;
				}
			}
			
			if(direction == "left"){
				currentPoint.x--;
			}
			else if(direction == "up"){
				currentPoint.y--;
			}
			else if(direction == "right"){
				currentPoint.x++;
			}
			else if(direction == "down"){
				currentPoint.y++;
			}
		}
				
		for(int i = 0; i < height; i++){
			cout << map[i] << '\n';
		}
	}
}
