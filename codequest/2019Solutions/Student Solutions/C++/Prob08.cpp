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

int t, grid[25][25], x, y;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> t;
    while (t--){
        cin >> x >> y;
        memset(grid, 0, sizeof(grid));
        grid[x][y] = 100;
        for (int i = 0; i < 20; i++){
            for (int j = 0; j < 20; j++){
                if (i == x && j == y) continue;
                if (max(abs(x - i), abs(y - j)) == 1) grid[i][j] = 50;
                else if (max(abs(x - i), abs(y - j)) == 2) grid[i][j] = 25;
                else grid[i][j] = 10;
            }
        }

        for (int i = 0; i < 20; i++){
            for (int j = 0; j < 20; j++){
                cout << grid[i][j];
                if (j != 19) cout << " ";
            }

            cout << endl;
        }
    }
    return 0;
}
