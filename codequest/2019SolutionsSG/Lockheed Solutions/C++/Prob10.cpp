#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

char getShiftedValue(char charIn, int shiftVal){
	if(charIn == ' ')
		return charIn;

	int counter = 0;
	if(shiftVal > 0){
		while(counter < shiftVal){
			if(charIn == 'z'){
				charIn = 'a' - 1;
			}
			charIn++;
			counter++;
		}
	}
	else if(shiftVal < 0){
		while(counter > shiftVal){
			if(charIn == 'a'){
				charIn = 'z' + 1;
			}
			charIn--;
			counter--;
		}
	}
	return charIn;
}

int main(){
	int iterations;
	cin >> iterations;

	int shiftVal;
	string message;
	for(int i = 0; i < iterations; i++){
		cin >> shiftVal;
		cin.ignore();
		getline(cin, message);
		
		shiftVal *= -1;
		for(unsigned int j = 0; j < message.length(); j++){
			message[j] = getShiftedValue(message[j], shiftVal);		
		}
		cout << message << endl;
	}

	return 0;
}

