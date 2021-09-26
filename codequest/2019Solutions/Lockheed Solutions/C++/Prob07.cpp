#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int iterations;
	cin >> iterations;

	for(int i = 0; i < iterations; i++) {
		int inputs;
		cin >> inputs;
		vector<double> imgVals;

		for(int j = 0; j < inputs; j++){
			double nextVal;
			cin >> nextVal;
			imgVals.push_back(nextVal);
		}

		double minVal = *min_element(imgVals.begin(),imgVals.end());
		double maxVal = *max_element(imgVals.begin(),imgVals.end());
			

		for(int j = 0; j < inputs; j++){
			double numerator = imgVals[j] - minVal;
			double denominator = maxVal - minVal;
			double output = (numerator / denominator) * 255;
			cout << round(output) << endl;
		}
	}

	return 0;
}

