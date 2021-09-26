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
#define pi acos(-1.0)

int main() {
	int t; cin >> t;
	M00(cs, t) {
		long double k; cin >> k;
		k *= 2 * pi;
		k += 40075;
		k *= 10;
		k = round(k);
		k /= 10;
		cout << fixed << setprecision(1) << k << "\n";
	}
}
