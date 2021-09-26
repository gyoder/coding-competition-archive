// Recommended includes for all problems. Some problems
// may require additional libraries.
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
// Added for this problem
#include <sstream>
using namespace std;

int main()
{
	int testCases;
	cin >> testCases;
	string dummy;
	getline(cin, dummy);
	
	for(int testcase = 0; testcase < testCases; testcase++){
		string input;
		getline(cin, input);
		
		// safety
		int rIndex = input.find("\r");
		if(rIndex > 0){
			input = input.substr(0, rIndex);
		}
		
		int spaceIdx = input.find(" ");
		string aString = input.substr(0, spaceIdx);
		string bString = input.substr(spaceIdx + 1);
		
		double a, b;
		istringstream aStream(aString);
		istringstream bStream(bString);
		aStream >> a;
		bStream >> b;
		
		cout << aString << '+' << bString << "i ";
		
		double a0 = a;
		double b0 = b;
		int iterations = 1;
		double abs = sqrt((a * a) + (b * b));
		
		while(abs < 100.0 && iterations <= 50){
			iterations++;
			
			double prevA = a;
			double prevB = b;
			a = (prevA * prevA) - (prevB * prevB) + a0;
			b = (2 * prevA * prevB) + b0;
			
			abs = sqrt((a * a) + (b * b));
		}
		
		if(iterations <= 10){
			cout << "RED";
		}
		else if(iterations <= 20){
			cout << "ORANGE";
		}
		else if(iterations <= 30){
			cout << "YELLOW";
		}
		else if(iterations <= 40){
			cout << "GREEN";
		}
		else if(iterations <= 50){
			cout << "BLUE";
		}
		else{
			cout << "BLACK";
		}
		
		cout << '\n';
	}
}
