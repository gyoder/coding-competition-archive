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

int t, n;
vector <double> v;
double Min, Max, a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> t;
    while (t--){
        cin >> n;
        v.clear();
        Min = 1e18, Max = -1e18;
        for (int i = 1; i <= n; i++){
            cin >> a;
            v.push_back(a);
            chmin(Min, a);
            chmax(Max, a);
        }

        for (double& i : v){
            i = ((i - Min) / (Max - Min)) * 255;
        }

        for (double& i : v) cout << (int)round(i) << endl;
    }
    return 0;
}
