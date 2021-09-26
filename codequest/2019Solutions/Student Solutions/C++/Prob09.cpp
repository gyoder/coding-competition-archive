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

int t, m, s, h;
string st;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> t;
    getline(cin, st);
    while (t--){
        getline(cin, st);
        m = h = s = 0;
        for (int i = 0; i < st.length(); i++){
            if (st[i] == 'm'){
                if (i > 1){
                    if (isdigit(st[i - 2])) m += (st[i - 2] - '0') * 10;
                    if (isdigit(st[i - 1])) m += (st[i - 1] - '0');
                }
                else {
                    if (isdigit(st[i - 1])) m += (st[i - 1] - '0');
                }
            }

            if (st[i] == 's'){
                if (i > 1){
                    if (isdigit(st[i - 2])) s += (st[i - 2] - '0') * 10;
                    if (isdigit(st[i - 1])) s += (st[i - 1] - '0');
                }else {
                    if (isdigit(st[i - 1])) s += (st[i - 1] - '0');
                }
            }

            if (st[i] == 'h'){
                if (i > 1){
                    if (isdigit(st[i - 2])) h += (st[i - 2] - '0') * 10;
                    if (isdigit(st[i - 1])) h += (st[i - 1] - '0');
                }else {
                    if (isdigit(st[i - 1])) h += (st[i - 1] - '0');
                }
            }
        }

        if (h < 10) cout << "0" << h << ":";
        else cout << h << ":";
        if (m < 10) cout << "0" << m;
        else cout << m;
        cout << ":";
        if (s < 10) cout << "0" << s << endl;
        else cout << s << endl;
    }
    return 0;
}
