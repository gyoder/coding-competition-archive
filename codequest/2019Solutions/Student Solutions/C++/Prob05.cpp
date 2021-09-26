#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
constexpr int inf = 0x3f3f3f3f;
constexpr double EPS = 1e-30;
constexpr double PI = atan(1) * 4;

template <typename T> inline bool chmax(T& x, T y) {return x < y ? x = y, 1 : 0;}
template <typename T> inline bool chmin(T& x, T y) {return x > y ? x = y, 1 : 0;}
inline int LSB(int i) {return (i & -i);}

int t, n, a, b;
bool good;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> t;
    while (t--){
        cin >> a >> b >> n;
        good = false;
        while (b && n >= 5) n -= 5, b--;
        if (n == 0) good = true;
        while (a && n >= 1) n -= 1, a--;
        if (n == 0) good = true;
        if (good) cout << "true" << endl;
        else cout << "false" << endl;
    }
    return 0;
}
