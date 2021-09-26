// LMCoin.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <limits>

using namespace std;

typedef numeric_limits<long double> dbl;

int main(int argc, char* argv[])
{
	cout.precision(dbl::max_digits10);
	
	string line;
	getline(cin, line);

	while (getline(cin,line))
	{
		vector<int> datavalues;
		int value = 0;
		size_t pos = line.find(' ');
		while (pos != string::npos)
		{
			value = 0;
			for (int i = 0; i < pos; i++)
			{
				value += line[i] - 'a' + 1;
			}
			datavalues.push_back(value);
			line = line.substr(pos + 1);
			pos = line.find(' ');
		}
		value = 0;
		for (int i = pos + 1; i < line.size(); i++)
		{
			value += line[i] - 'a' + 1;
		}
		datavalues.push_back(value);
		vector<long long> datevalues;
		getline(cin,line);
		pos = line.find(' ');
		while (pos != string::npos)
		{
			long long storage = stoll(line.substr(0,pos));
			datevalues.push_back(storage);
			line = line.substr(pos + 1);
			pos = line.find(' ');
		}
		datevalues.push_back(stoll(line.substr(pos+1)));
		long long priorhashint = 0;
		long double priorhash = 0;
		for (int i = 0 ; i < 10; i++)
		{	
			long long intermediate = 0;
			intermediate = ((datevalues[i] + datavalues[i] + i +1 + priorhashint + priorhash) * 50.0L ) / 147.0L;
			priorhash = (long double)(((long double)datevalues[i] + (long double)datavalues[i] + (long double)i + (long double)1) * (long double)50.0L + ((long double)priorhashint + priorhash) * (long double)50.0L ) / (long double)147.0L - intermediate;
			priorhashint = intermediate;
		}
		cout << (long long)((long double)priorhashint + priorhash + 0.5L) << endl;
	}

	return 0;
}

