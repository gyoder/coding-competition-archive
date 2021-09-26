//============================================================================
// Name        : Prob00B.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>
#include <set>
#include <stack>
#include <sstream>

using namespace std;

int main() {
	int testCases;
	cin >> testCases;
	string dummy;
	getline(cin, dummy);

	for (int testcase = 0; testcase < testCases; testcase++) {
		string line;
		getline(cin, line);
		/*stringstream ss(line);

		char c;
		do{
			ss >> c;
			if(c > 64 && c < 91){}
			else
				break;
			c = c + 32;
			cout << c;
		}while(1);*/
		std::transform(line.begin(),line.end(),line.begin(),::tolower);
		cout << line << '\n';
	}

}
