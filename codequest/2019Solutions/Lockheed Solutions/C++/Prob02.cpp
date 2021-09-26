// SumItUp.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	string line;
	getline(cin, line);
	while (getline(cin, line))
	{
		int separator = line.find(' ');
		int first = stoi(line.substr(0,separator));
		int second = stoi(line.substr(separator));

		int calc = first + second;
		if (first == second)
			calc *= 2;
		cout << calc << endl;
	}
		
	return 0;
}

