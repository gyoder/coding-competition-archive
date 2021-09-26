// NoMoreShouting.cpp : Defines the entry point for the console application.
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
		for (int i = 0; i < line.size(); i++)
		{
			cout << (char) tolower(line[i]) ;
		}
		cout << endl;
	}
		
	return 0;
}

