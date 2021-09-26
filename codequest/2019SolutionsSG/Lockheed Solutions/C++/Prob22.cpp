#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <vector>
#include <utility>
#include <algorithm>

#define customRound(x,d) ((floor(((x)*pow(10,d))+.5))/pow(10,d));

using namespace std;

time_t getDate(string lastChangedDate, string lastChangedTime){
	string minutes, hours, day, month, year;
	int index;	
	
	index = lastChangedDate.find("/");
	day = lastChangedDate.substr(0, index);
   	lastChangedDate.erase(0, index + 1);

	index = lastChangedDate.find("/");
	month = lastChangedDate.substr(0, index);
   	lastChangedDate.erase(0, index + 1);
	
	year = lastChangedDate;

	index = lastChangedTime.find(":");
	hours = lastChangedTime.substr(0, index);
   	lastChangedTime.erase(0, index + 1);

	minutes = lastChangedTime;

	struct tm dateStruct = {0,stoi(minutes),stoi(hours),stoi(day),stoi(month)-1,stoi(year) - 1900};  
	time_t date = mktime(&dateStruct);	
	return date;
}

bool compareFunc(tuple<double, double, string> &a, tuple<double, double, string> &b){
    return get<0>(a) > get<0>(b);
}

int main(){
	int iterations, numFiles;
	double hardDriveSize, sizeKB;
	string lastChangedDate, lastChangedTime, amOrPm, fileName;
	struct tm codeQuestDateStruct = {0,0,0,27,3,2019 - 1900}; //April 27, 2019 
	time_t codeQuestDate = mktime(&codeQuestDateStruct);	

	cin >> iterations;
	for(int i = 0; i < iterations; i++) {
		vector<tuple<double, double, string> > fileVec;
		cin >> numFiles >> hardDriveSize;
		for(int j = 0; j < numFiles; j++){
			cin >> lastChangedDate >> lastChangedTime >> amOrPm >> sizeKB >> fileName;
			time_t date = getDate(lastChangedDate, lastChangedTime);
			double difference = ceil((difftime(codeQuestDate, date) / (60 * 60 * 24)));
			if(amOrPm == "PM")
				difference -= .5;
			
			double sizeMB = sizeKB / 1000.0;
			double score = difference * sizeMB;
			fileVec.push_back(make_tuple(score, sizeKB, fileName));
		}

 		sort(fileVec.begin(), fileVec.end(), compareFunc);

		hardDriveSize *= 1000000; //convert to KB
		double sizeCleared = 0;
		int index = 0;
		while(sizeCleared <= (hardDriveSize * .25)){
			tuple<double,double,string> t = fileVec[index];
			double score = customRound(get<0>(t), 3);
			cout << get<2>(t) << " " << setprecision(3) << fixed << score << endl;
			sizeCleared += get<1>(t);
			index++;
		}
	}

	return 0;
}
