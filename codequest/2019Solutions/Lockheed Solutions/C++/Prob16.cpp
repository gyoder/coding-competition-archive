// Recommended includes for all problems. Some problems
// may require additional libraries.
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

int fromHex(char a, char b){
	int value = 0;
	
	if(a >= 'A' && a <= 'F'){
		value += ((int) a - 55) * 16;
	}
	else{
		value += ((int) a - 48) * 16;
	}
	
	if(b >= 'A' && b <= 'F'){
		value += ((int) b - 55);
	}
	else{
		value += ((int) b - 48);
	}
	
	return value;
}

int main()
{
	int testCases;
	cin >> testCases;
	string dummy;
	getline(cin, dummy);
	
	for(int testcase = 0; testcase < testCases; testcase++){
		int keyCount;
		cin >> keyCount;
		getline(cin, dummy);
		
		string ciphertext;
		getline(cin, ciphertext);
		
		for(int index = 0; index < keyCount; index++){
			string key;
			getline(cin, key);
			
			cout << '[';
			
			for(int i = 0; i < 64; i++){
				char cipherHex1 = ciphertext[i * 2];
				char cipherHex2 = ciphertext[(i * 2) + 1];
				
				char keyHex1 = key[i * 2];
				char keyHex2 = key[(i * 2) + 1];
				
				int cipherValue = fromHex(cipherHex1, cipherHex2);
				int keyValue = fromHex(keyHex1, keyHex2);
				int plainValue = cipherValue ^ keyValue;
				
				cout << (char) plainValue;
			}
			
			cout << "]\n";
		}
	}
}
