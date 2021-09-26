// TimeAndTimeAgain.cpp : Defines the entry point for the console application.
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
		int hourindex = line.find("h");
		int minuteindex = line.find("m");
		int secondindex = line.find("s");
		int hours = 0;
		int minutes = 0;
		int seconds = 0;
		try{
			hours = stoi(line.substr(hourindex-2,2));
		}
		catch(...){
			if (hourindex != string::npos)
				hours = stoi(line.substr(hourindex-1,1));
		}
		try {minutes = stoi(line.substr(minuteindex - 2,2));}
		catch(...){
			if (minuteindex != string::npos)
				minutes = stoi(line.substr(minuteindex - 1,1));
		}
		try {seconds = stoi(line.substr(secondindex - 2, 2));}
		catch(...){
			if (secondindex != string::npos)
				seconds = stoi(line.substr(secondindex - 1, 1));
		}
		char output[9];
		sprintf(output, "%02d:%02d:%02d", hours, minutes, seconds);
		cout << output << endl;

	}

	return 0;
}

