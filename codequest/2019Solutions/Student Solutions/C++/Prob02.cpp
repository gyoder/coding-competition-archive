#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int parseComma(vector<string> &base, string s) {
	string temp = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ',') {
			if (temp.size() != 0) base.push_back(temp), temp.clear();
		}
		else {
			temp += s[i];
		}
	}
	if (temp.size() != 0) base.push_back(temp), temp.clear();
	return base.size();
}
int main() {
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	int T; cin >> T;
	cin.ignore();
	for (int i = 0; i < T; i++) {
		int a, b;
		cin >> a >> b;
		if (a == b) cout << a * 4 << endl;
		else cout << a + b << endl;
	}
	return 0;
}