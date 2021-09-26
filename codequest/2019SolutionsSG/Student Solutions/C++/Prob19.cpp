
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cctype>
#include <algorithm>
#include <math.h>

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
	for (int z = 0; z < tc; z++)
	{
		int n2; cin >> n2;
		string s;
		getline(cin, s);
		string *arr= new string[n2];
		for (int j = 0; j < n2; j++) {
			getline(cin, s);
			out.clear();
			splitter(s, ".");
			for (int k = 0; k < 4; k++) {
				int a = stoi(out[k]);
				for (int j2 = 256; j2 > 1; j2 /= 2) {
					if ((a%j2) >= j2 / 2) {
						arr[j] += '1';
					}
					else {
						arr[j] += '0';
					}
				}
			}
		}


		string blockip;
		int similars = 0;
		for (int k = 0; k < 32; k++) {
			bool works = true;
			for (int hi = 0; hi < n2; hi++) {
				if (arr[hi][k] != arr[0][k]) {
					works = false;
					break;
				}
			}
			if (!works) {
				break;
			}
			else {
				similars++;
				blockip += arr[0][k];
			}

		}
		for (int f = similars; f < 32; f++) {
			blockip += "0";
		}
		for (int hey = 0; hey < 4; hey++) {
			int total = 0;
			for (int hey2 = 0; hey2 < 8; hey2++) {
				total *= 2;
				total += blockip[hey * 8 + hey2] - '0';
			}
			cout << total;
			if (hey < 3) {
				cout << ".";
			}
			else {
				cout << "/";
			}

		}
		cout << similars << endl;
	}
}
