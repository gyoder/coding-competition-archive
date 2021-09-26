#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, N)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
int T, N=9, grid[9][9];

bool go(int i, int j) {
    if (j == 9) {i++; j = 0;}
    if (i == 9) return true;
    //w<< i s j<<e;
    if (grid[i][j] != 0) return go(i, j+1);
    For (k, 1, 10) {
        bool good = true;
        For (x, 0, 9) if (grid[i][x] == k || grid[x][j] == k) good = false;
        For (i1, 3*(i/3), 3*(i/3) + 3) For (j1, 3*(j/3), 3*(j/3) + 3) {
            if (grid[i1][j1] == k) good = false;
        }
        if (good) {
            grid[i][j] = k;
            //w<< "try" s k s "at" s i s j<<e;
            if (go(i, j+1)) {
                //w<< "put" s k s "at" s i s j<<e;
                return true;
            }
            grid[i][j] = 0;
        }
    }
    return false;
}

main() {
    //ifstream cin ("test.in");
    //ifstream cin(".in"); ofstream cout(".out");
    ios_base::sync_with_stdio; cin.tie(0);
    cin >> T;
    For (t, 0, T) {
        ffa {
            char a; cin >> a;
            if (a == '_') grid[i][j] = 0;
            else grid[i][j] = a-'0';
        }
        go(0, 0);
        ffi {
            ffj w<< grid[i][j]; w<<e;
        }
    }
}
