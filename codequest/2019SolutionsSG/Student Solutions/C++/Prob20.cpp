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

string A = "Accipitridae";
string B = "Passeridae";
string C = "Cathartidae";

int main() {
	int t; cin >> t;
	M00(cs, t) {
		int x, y; cin >> x >> y;
		vector<pair<vector<long double>, int>> v;
		M00(i, x) {
			string s; cin >> s;
			long double a, b, c, d; cin >> a >> b >> c >> d;
			long double aa = a; long double bb = b; long double cc = c; long double dd = d;
			int t = 0;
			if(s == A) t = 0;
			if(s == B) t = 1;
			if(s == C) t = 2;
			//cout << s << " " << t << "\n";
			vector<long double> v1;
			v1.push_back(aa); v1.push_back(bb); v1.push_back(cc); v1.push_back(dd);
			v.push_back(make_pair(v1,t));
		}
		M00(i, y) {
			long double a, b, c, d; cin >> a >> b >> c >> d;
			long double aa = a; long double bb = b; long double cc = c; long double dd = d;
			vector<pair<long double,int>> distances;
			M00(j, x) {
				long double dis = 0;
				dis += pow(abs(aa - (v[j].first)[0]), (long double)2);
				dis += pow(abs(bb - (v[j].first)[1]), (long double)2);
				dis += pow(abs(cc - (v[j].first)[2]), (long double)2);
				dis += pow(abs(dd - (v[j].first)[3]), (long double)2);
				distances.push_back(make_pair(dis,v[j].second));
			}
			sort(distances.begin(), distances.end());
			int cnt[3];
			cnt[0] = 0; cnt[1] = 0; cnt[2] = 0;
			for(int j = 0; j < x; j++) {
				int type = distances[j].second;
				cnt[type]++;
				if(j >= 4) {
					int mx = max(cnt[0], cnt[1]); mx = max(mx, cnt[2]);
					int numleader = 0;
					if(cnt[0] == mx) numleader++;
					if(cnt[1] == mx) numleader++;
					if(cnt[2] == mx) numleader++;
					if(numleader == 1) {
						M00(k, 3) if(cnt[k] == mx) {
							if(k == 0) cout << A << "\n";
							else if(k == 1) cout << B << "\n";
							else if(k == 2) cout << C << "\n";
						}
						break;
					}
				}
			}
		}
	}
}
