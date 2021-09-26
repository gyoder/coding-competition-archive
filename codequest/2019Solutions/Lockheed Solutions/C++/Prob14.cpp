#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <utility>

using namespace std;

//returns index of first city visited
//returns -1 if not found 
unsigned int findFirstCity(vector<pair<string, string> > &tripVec){
	for(unsigned int i = 0; i < tripVec.size(); i++){
		string firstCity = tripVec[i].first;
		bool notFirst = false;
		for(unsigned int j = 0; j < tripVec.size(); j++){
			if(firstCity.compare(tripVec[j].second) == 0){
				notFirst = true;
				break;
			}		
		}
		if(!notFirst)
			return i;
	}
	return -1;
}

vector<pair<string, string> > orderTrips(vector<pair<string, string> > &tripVec, unsigned int startIndex){
	vector<pair<string, string> > orderedVec;
	string currentCity = tripVec[startIndex].first;
	string destCity = tripVec[startIndex].second;
	orderedVec.push_back(make_pair(currentCity, destCity));

	for(unsigned int i = 0; i < tripVec.size(); i++){
		if(i == startIndex)
			continue;		
		if(destCity.compare(tripVec[i].first) == 0){
			currentCity = tripVec[i].first;
			destCity = tripVec[i].second;
			orderedVec.push_back(make_pair(currentCity, destCity));
			i = -1;
		}
	}
	return orderedVec;
}


int main(){
	int iterations;
	cin >> iterations;

	for(int i = 0; i < iterations; i++) {
		//first = departure city, second = arrival city
		vector<pair<string, string> > tripVec;
		int trips;
		string deptCity, arrivalCity;
		cin >> trips;

		//store out of order trips in tripVec
		for(int j = 0; j < trips; j++){
			cin >> deptCity >> arrivalCity;
			tripVec.push_back(make_pair(deptCity, arrivalCity));
		}
	
		unsigned int firstIndex = findFirstCity(tripVec);
		vector<pair<string, string> > orderedTrips = orderTrips(tripVec, firstIndex);

		//print trips in reverse order
		for(int j = orderedTrips.size()-1; j > -1; j--){
			cout << orderedTrips[j].second << endl;
			if(j == 0)
				cout << orderedTrips[j].first << endl;
		}

	}

	return 0;
}

