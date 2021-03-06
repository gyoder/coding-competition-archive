//
// Created by Allen Li on 2019-04-27.
//

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<double, double> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;

template<class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

template<class T>
inline void MAX(T &a, T b) { if (a < b) a = b; }

template<class T>
inline void MIN(T &a, T b) { if (a > b) a = b; }

template<class T>
inline void MODA(T &a, T b) {
	a %= b;
	if (a < 0) a += b;
}

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(20)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define long ll
#define finish(x) return cout << (x) << '\n', 0
#define F0R(i, a) for(int (i)=0;(i)<(a);++(i))
#define FOR(i, a, b) for(int (i)=(a);(i)<(b);++(i))
#define F0Rd(i, a) for(int (i)=a;(i)>=0;--(i))
#define FORd(i, a, b) for(int (i)=a;(i)>=(b);--(i))
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

#define mp make_pair
#define pb push_back
#define pf push_front
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const int NINF = -0x3f3f3f40;

int main() {
	FAST_IO;
	int t; cin >> t;
	while(t--) {
		int n = 10;
		string arr[n];
		F0R(i, n) cin >> arr[i];
		ld val[n];
		F0R(i, n) {
			ll num = 0;
			F0R(j, arr[i].size()) {
				num += arr[i][j]-'a'+1;
			}
			val[i] = num;
		}
		ld answ[n];
		F0R(i, n) {
			ld lst;
			if(!i) lst = 0;
			else lst = answ[i-1];
			ld tms; cin >> tms;
			answ[i] = tms + val[i] + (i+1) + lst;
			answ[i] *= 50;
			answ[i] /= 147;
		}
		cout << (int)(answ[9]+0.5) << '\n';
	}
}

