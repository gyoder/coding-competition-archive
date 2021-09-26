#include <iostream>
#include <cmath>
#include <vector>
#include <utility> 
#include <algorithm>

using namespace std;

class Bird{
	private:
		double length, width, wingSpan, wingAngle;
		string familyName;
	public:
		Bird(string, double, double, double, double);
		string getFamilyName(){return familyName;}
		double getLength(){return length;}
		double getWidth(){return width;}
		double getWingSpan(){return wingSpan;}
		double getWingAngle(){return wingAngle;}
};

Bird::Bird(string familyName, double length, double width, double wingSpan, double wingAngle){
	this->familyName = familyName;
	this->length = length;
	this->width = width;
	this->wingSpan = wingSpan;
	this->wingAngle = wingAngle;
}

ostream& operator<<(ostream &strm, Bird &bird) {
  return strm << "family: " << bird.getFamilyName() << " length: " << bird.getLength() << " width: " << bird.getWidth() << " wingSpan: " << bird.getWingSpan() << " wingAngle: " << bird.getWingAngle() << endl;
}

bool compareFunc(pair<double, Bird> &a, pair<double, Bird> &b){
    return a.first < b.first;
}

bool isATie(int a, int b, int c){
 	int maxVal = max(max(a, b), c);
	//cout << "maxVal is " << maxVal << endl;
	if(a == maxVal && (b != maxVal && c != maxVal))
		return false;
	if(b == maxVal && (a != maxVal && c != maxVal))
		return false;
	if(c == maxVal && (a != maxVal && b != maxVal))
		return false;
	return true;
}

int main(){
	string birdFamily0 = "Accipitridae";
	string birdFamily1 = "Passeridae";
	string birdFamily2 = "Cathartidae";
		
	int iterations;
	cin >> iterations;

	int knownBirds, unknownBirds;
	string birdFamily;
	double length, width, wingSpan, wingAngle;
	
	for(int i = 0; i < iterations; i++) {
		cin >> knownBirds >> unknownBirds;
		vector<Bird> knownVec;

		for(int j = 0; j < knownBirds; j++){
			cin >> birdFamily >> length >> width >> wingSpan >> wingAngle;
			knownVec.push_back(Bird(birdFamily, length, width, wingSpan, wingAngle));
		}	

		for(int j = 0; j < unknownBirds; j++){
			cin >> length >> width >> wingSpan >> wingAngle;
			vector<pair<double, Bird> > birdDistVec;
			int comparisons = 5;
			int bird0 = 0;
			int bird1 = 0; 
			int bird2 = 0;

			for(unsigned int k = 0; k < knownVec.size(); k++){
				Bird bird = knownVec[k];
				double distance = sqrt(pow(length - bird.getLength(),2) + pow(width - bird.getWidth(),2) + pow(wingSpan - bird.getWingSpan(),2) + pow(wingAngle - bird.getWingAngle(),2));
				birdDistVec.push_back(make_pair(distance, bird));
			}

			sort(birdDistVec.begin(), birdDistVec.end(), compareFunc); //sort so closest matches are at the beginning of the vector
			for(int k = 0; k < comparisons; k++){
				if(birdDistVec[k].second.getFamilyName() == birdFamily0)
					bird0++;
				else if(birdDistVec[k].second.getFamilyName() == birdFamily1)
					bird1++;
				else if(birdDistVec[k].second.getFamilyName() == birdFamily2)
					bird2++;
				
				if(k == comparisons - 1){ //last time through loop - need to increase comparisons if currently a tie
					if(isATie(bird0, bird1, bird2)){
						comparisons++;
					}
				}
			}
			
			int maxCount = max(max(bird0, bird1), bird2);
			if(maxCount == bird0)
				cout << birdFamily0 << endl;
			else if(maxCount == bird1)
				cout << birdFamily1 << endl;
			else if(maxCount == bird2)
				cout << birdFamily2 << endl;
		}
	}
	return 0;
}
