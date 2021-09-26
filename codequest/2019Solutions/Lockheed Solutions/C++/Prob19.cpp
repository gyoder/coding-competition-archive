// NetworkRanger.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main(int argc, char* argv[])
{
	string line;
	getline(cin, line);
	while(getline(cin, line))
	{
		int count = stoi(line);
		vector<int> addresses[4];
		for (int i = 0; i < count; i++)
		{
			getline(cin, line);
			int periodpos = line.find('.');
			addresses[0].push_back(stoi(line.substr(0,periodpos)));
			line = line.substr(periodpos+ 1);
			periodpos = line.find('.');
			addresses[1].push_back(stoi(line.substr(0,periodpos)));
			line = line.substr(periodpos + 1);
			periodpos = line.find('.');
			addresses[2].push_back(stoi(line.substr(0,periodpos)));
			addresses[3].push_back(stoi(line.substr(periodpos + 1)));
		}
		int totaldiff = 0;
		int finalip[4];
		for (int i = 0; i < 4; i++)
		{
			int min = *min_element(addresses[i].begin(), addresses[i].end());
			int max = *max_element(addresses[i].begin(), addresses[i].end());
			
			if (max - min == 0)
			{
				totaldiff += 8;
				cout << *addresses[i].begin() ;
				if (i < 3)
				{
					cout << '.';
				}
				else
				{
					cout<<'/'<<totaldiff<<endl;
				}
			}
			else
			{
				
				int index = distance(addresses[i].begin(), min_element(addresses[i].begin(), addresses[i].end()));
				int bitcheck = 128;
				while (min / bitcheck == max / bitcheck && bitcheck > 1)
				{
					totaldiff++;
					bitcheck /= 2;
				}
				cout<<addresses[i].at(index) - addresses[i].at(index)%bitcheck;
				for (int j = i + 1; j < 4; j++)
					cout<<'.'<<0;
				cout<<'/'<<totaldiff<<endl;
				break;
			}
		}
		

	}
		
	return 0;
}

