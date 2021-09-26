#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = 3.14159265358979323846;
const double EARTH_RADIUS = 40075.0 / (2 * PI); //in KM

int main(){
	int iterations;
	int altitude;
	double distance;
	cin >> iterations;

	for(int i = 0; i < iterations; i++) {
		cin >> altitude;
		distance = 2 * PI * (EARTH_RADIUS + altitude);
		cout << setprecision(1) << fixed << distance << endl;
	}

	return 0;
}
