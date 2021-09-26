#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

void updatePercentages(vector<vector<double> > &gameVec, double chance){
	for(unsigned int i = 0; i < gameVec.size(); i++){
		if(gameVec[i][1] == 0 && gameVec[i][2] == 0)
			gameVec[i][0] += chance;
	}
}

void setupGame(vector<vector<double> > &gameVec, int doors, double origChance){
	for(int j = 0; j < doors; j++){
		vector<double> innerVec;
		innerVec.push_back(origChance);
		if(j == 0)
			innerVec.push_back(1); //always choose first door originally
		else
			innerVec.push_back(0);
		innerVec.push_back(0);
		gameVec.push_back(innerVec); 
	}
}

double selectNextDoor(vector<vector<double> > &gameVec){
	double maxChance = -1;
	for(auto door : gameVec){
		if(door[0] > maxChance)
			maxChance = door[0];
	}

	for(unsigned int i = 0; i < gameVec.size(); i++){
		if(gameVec[i][0] == maxChance && gameVec[i][2] == 0){
			gameVec[i][1] = 1;
			break;
		}
	}
	return maxChance;
}

int main(){
	int iterations;
	int doors, rounds, doorsPerRound;
	double finalChance;
	cin >> iterations;

	for(int i = 0; i < iterations; i++) {
		cin >> doors >> rounds >> doorsPerRound;
		double origChance = 100.0 / doors;
		finalChance = origChance; //acount for 0 rounds case

		// Setup intial gameVec
		// each inside vector is {chance, beenChosen, openedAlready}
		// 0 means false 1 means true
		vector< vector<double> > gameVec;
		setupGame(gameVec, doors, origChance);
		for(int j = 0; j < rounds; j++){
			int doorsOpened = 0;
			double chanceToDistribute = 0;
			for(int k = gameVec.size() - 1; k > -1; k--){
				if(gameVec[k][1] == 0 && gameVec[k][2] == 0){	
					gameVec[k][2]++; //opening this door
					chanceToDistribute += gameVec[k][0];
					doorsOpened++;
				}

				if(doorsOpened == doorsPerRound){	
					doors -= (doorsPerRound + 1);
					double chanceToAdd = chanceToDistribute / (double)doors;  					
					updatePercentages(gameVec, chanceToAdd);
					finalChance = selectNextDoor(gameVec);
					break;
				}			
			}
		}
		cout << setprecision(2) << fixed << finalChance << "%" << endl;
	}

	return 0;
}
