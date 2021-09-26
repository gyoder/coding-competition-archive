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

void rec(int a, string s){
	if(a == 0){
		cout << s << '\n';
		return;
	}
	rec(a - 1, s + "0");
	rec(a - 1, s + "1");
	return;
}

int main() {
	int testCases;
	cin >> testCases;
	string dummy;
	getline(cin, dummy);

	for (int testcase = 0; testcase < testCases; testcase++) {
		int x;
		cin >> x;
		string line;
		getline(cin, line);//garbage
		rec(x,"");
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
	}

}
