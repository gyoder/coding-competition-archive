#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
string retans(int a, string b) {
	bool B = (b == "false") ? false : true;
	if (a <= 60 + B * 5) return "no ticket";
	else if (a <= 80 + B * 5) return "small ticket";
	else return "big ticket";
}
int main() {
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		int a; string b;
		cin >> a >> b;
		cout << retans(a, b) << endl;
	}
	return 0;
}