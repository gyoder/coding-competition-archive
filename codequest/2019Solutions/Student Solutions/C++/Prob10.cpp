#include <iostream>

using namespace std;

string alph = "abcdefghijklmnopqrstuvwxyz";

int main() {
	int n; cin >> n;
	string temp; getline(cin, temp);
	for(int i = 0; i < n; i++) {
		int shift; cin >> shift;
		getline(cin, temp);
		string s; getline(cin, s);
		for(int j = 0; j < s.length(); j++) {
			char c = s[j];
			if(c == ' ') continue;
			else s[j] = alph[(26+(c-'a')-shift)%26];
		}
		cout << s << "\n";
	}
}
