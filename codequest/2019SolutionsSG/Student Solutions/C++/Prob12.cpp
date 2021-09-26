#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cctype>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;

vector<string> out;

void splitter(string input, const char* delim)
{
	int pos = input.find_first_of(delim);
	while (pos != string::npos)
	{
		if (pos != 0) { out.push_back(input.substr(0, pos)); }
		input = input.substr(pos + 1);
		pos = input.find_first_of(delim);
	}
	if (input.size() != 0)
	{
		out.push_back(input.substr(0));
	}
}

int main()
{
	int tc; cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		double nd, nr, dopr;
		cin >> nd >> nr >> dopr;
		double total = 100.00;
		double chance = 100.00 / nd;
		for (int j = 0; j < nr; j++)
		{
			total -= chance;
			nd -= dopr + 1;
			chance = total / nd;
		}
		cout << fixed << setprecision(2) << chance << "%" << endl;
	}
}
