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
	int len =10;
	int testCases;
	cin >> testCases;
	string dummy;
	getline(cin, dummy);
	bool arr[12][12] = {0};
	for (int testcase = 0; testcase < testCases; testcase++) {
		int gen;
		cin >> gen;
		string line;
		getline(cin, line);//garbage
		for(int r = 1; r < len + 1; r++){
			for(int c = 1; c < len + 1; c++){
				char a;
				cin >> a;
				arr[r][c] = a - 48;
			}
			getline(cin,line);
		}
		for(int a = 0; a < gen; a++){
			bool save[12][12] = {0};
		for(int r = 0; r < len + 2; r++){
			for(int c = 0; c < len + 2; c++){
				save[r][c] = arr[r][c];
			}
			}
		for(int r = 1; r < len + 1; r++){
			for(int c = 1; c < len + 1; c++){
				int count = 0;
				if(save[r-1][c-1])
					count++;
				if(save[r][c-1])
					count++;
				if(save[r+1][c-1])
					count++;
				if(save[r-1][c])
					count++;
				if(save[r+1][c])
					count++;
				if(save[r-1][c+1])
					count++;
				if(save[r][c+1])
					count++;
				if(save[r+1][c+1])
					count++;
				if(count < 2 && arr[r][c] == 1){
					arr[r][c] = 0;
				}
				else if(count < 4 && arr[r][c] == 1){
					arr[r][c] = 1;
				}
				else if(arr[r][c] == 1){
					arr[r][c] = 0;
				}
				else if(arr[r][c] == 0 && count == 3){
					arr[r][c] = 1;
				}
			}
		}
	}
		for(int r = 1; r < len + 1; r++){
			for(int c = 1; c < len + 1; c++){
				cout << arr[r][c];
			}
			cout << endl;
		}
	}
return 0;
}
