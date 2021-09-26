#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int ROWS = 20;
const int COLS = 20;

void printMatrix(vector<vector<int> > &matrix){
	for(vector<int> row : matrix){
		cout << row[0];
		for(unsigned int i = 1; i < row.size(); i++){
			cout << " " << row[i];
		}
		cout << endl;
	}
}

void alterMatrix(vector<vector<int> > &matrix, int row, int col, int val){
	if(col >= 0 && col < COLS && row >= 0 && row < ROWS && matrix[row][col] != 100 && matrix[row][col] != 50)
		matrix[row][col] = val;
}

int main(){
	int iterations;
	cin >> iterations;

	int row, col;
	vector<vector<int> > matrix(ROWS);
	
	// initial matrix to all 10%
	for(int i = 0; i < iterations; i++) {
		cin >> row >> col;
		for(int j = 0; j < ROWS; j++){
			vector<int> innerVec(COLS);
			for(int k = 0; k < COLS; k++)
				innerVec[k] = 10;
			matrix[j] = innerVec;
		}
	
		int rowArr50[] = {row - 1, row, row + 1};	
		int colArr50[] = {col - 1, col, col + 1};
		int rowArr25[] = {row - 2, row - 1, row, row + 1, row + 2};	
		int colArr25[] = {col - 2, col - 1, col, col + 1, col + 2};

		alterMatrix(matrix, row, col, 100);	
		for(int i : rowArr50){
			for(int j : colArr50)
				alterMatrix(matrix, i, j, 50);	
		}	
		for(int i : rowArr25){
			for(int j : colArr25)
				alterMatrix(matrix, i, j, 25);	
		}	

		printMatrix(matrix);
	}
}
