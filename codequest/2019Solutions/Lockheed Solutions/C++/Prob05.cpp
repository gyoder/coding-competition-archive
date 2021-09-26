#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int BIG_LENGTH = 5;
const int SMALL_LENGTH = 1;

int main(){
	int iterations;
	cin >> iterations;

	int numSmall, numBig, totalLength;

	for(int i = 0; i < iterations; i++) {
		cin >> numSmall >> numBig >> totalLength;
		bool foundCombo = false;
		int smallCount = 0;
		int length = numBig * BIG_LENGTH;
		while(length >= totalLength){
			if(length == totalLength){
				cout << "true" << endl;
				foundCombo = true;
			}
			length -= BIG_LENGTH;
		}
		if(foundCombo)
			continue;

		while(length <= totalLength && smallCount <= numSmall){
			if(length == totalLength){
				cout << "true" << endl;
				foundCombo = true;
			}
			length += SMALL_LENGTH;
			smallCount++;
		}
		if(!foundCombo)
			cout << "false" << endl;
	}

	return 0;
}

