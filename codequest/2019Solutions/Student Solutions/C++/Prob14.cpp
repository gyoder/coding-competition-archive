#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <assert.h>
#include <sstream>

using namespace std;

#define M00(i, n) for(int i=0;i<n;i++)
#define M00d(i, n) for(int i=n-1;i>=0;i--)
#define pi acos(-1.0)
#define sq(a) pow(a,2)

int main() {
	int t; cin >> t;
	M00(cs, t) {
		int x; cin >> x;
		map<string, int> compress;
		map<string, string> too;
		map<int, string> rev;
		M00(i, x) {
			string a, b; cin >> a >> b;
			compress[a] = 0;
			compress[b] = 0;
			too[a]=b;
		}
		int temp = 0;
		for(auto& k : compress) k.second = temp++;
		for(auto k: compress) rev[k.second] = k.first;

		vector<int> to;
		to.resize(x+1);
		M00(i, x+1) to[i] = -1;
		for(auto w: too) to[compress[w.first]] = compress[w.second];

		vector<int> from;
		from.resize(x+1);
		M00(i, x+1) from[i] = -1;
		for(int i = 0; i < x+1; i++) {
			if(to[i] != -1) from[to[i]] = i;
		}

		int r = -1;
		M00(i, x+1) if(from[i] == -1) {
			r = i;
		}

		int cur = r;
		vector<string> res;
		M00(i, x+1) {
			res.push_back(rev[cur]);
			cur = to[cur];
		}
		M00d(i, x+1) cout << res[i] << "\n";
	}
}
