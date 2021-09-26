#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	int iterations;
	unsigned int speed, bdayIncrease;
	string birthday;
	cin >> iterations;
	
	for(int i = 0; i < iterations; i++) {
		bdayIncrease = 0;
		cin >> speed >> birthday;
		if(birthday == "true")
			bdayIncrease = 5;
		
		if(speed <= 60 + bdayIncrease)
			cout << "no ticket" << endl;
		else if(speed <= 80 + bdayIncrease)
			cout << "small ticket" << endl;
		else
			cout << "big ticket" << endl;	
	}
	
	return 0;
}

