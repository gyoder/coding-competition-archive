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

const int MAX_N = 5000;
int n, m, b;
int arr[MAX_N][MAX_N];

bool inbounds(int x, int y) {
	return (x >= 0 && x < n && y >= 0 &&  y< m);
}

int main() {
	int t; cin >> t;
	M00(cs, t) {
		cin >> n >> m >> b;
		M00(i, n) M00(j, m) arr[i][j] = 0;
		M00(i, b) {
			int x, y; cin >> x >> y;
			//x = n-x-1;
			arr[x][y]=-1;
		}
		M00(i, n) M00(j, m) if(arr[i][j] == 0) {
			for(int dx = -1; dx <= 1; dx++) {
				for(int dy = -1; dy <= 1; dy++) {
					if(dx == 0 && dy == 0) continue;
					if(inbounds(i+dx, j+dy) && arr[i+dx][j+dy] == -1) arr[i][j]++;
				}
			}
		}
		M00(i, n) {
			M00(j, m) {
				if(arr[i][j] == -1) cout << "*";
				else cout << arr[i][j];
			}
			cout << "\n";
		}
	}

}
