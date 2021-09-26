#include <stdio.h>

void print(int board[9][9]) {
	for(int row = 0; row < 9; row++) {
		for(int col = 0; col < 9; col++) {
			printf("%d", board[row][col]);
		}
		printf("\n");
	}
}

// Check if this set contains any duplicates
// retuns 1 for no duplicates, otherwise 0
int check_set(int set[9]) {
	// track which digits have appeared
	// found[X] == 1 means that X has been seen
	int found[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for(int i = 0; i < 9; i++) {
		// don't worry about 0s, they could be anyhting
		if(set[i] != 0 && found[set[i]] == 1) {
			return 0;
		}
		found[set[i]] = 1;
	}

	return 1;
}

// Check if the column contains any duplicates
// retuns 1 for no duplicates, otherwise 0
int check_col(int board[9][9], int col) {
	int set[9];
	for(int row = 0; row < 9; row++) {
		set[row] = board[row][col];
	}

	return check_set(set);
}

// Check if this "subgrid" contains any duplicates
// retuns 1 for no duplicates, otherwise 0
int check_square(int board[9][9], int in_row, int in_col) {
	int set[9];
	for(int row = 0; row < 3; row++) {
		for(int col = 0; col< 3; col++) {
			set[(row*3) + col] = board[(in_row*3) + row][(in_col*3) + col];
		}
	}

	return check_set(set);
}


// Check if the entire board is a valid solution
// retuns 1 for valid, otherwise 0
int check_board(int board[9][9]) {
	// Check rows
	for(int row = 0; row < 9; row++) {
		if(!check_set(board[row])) {
			return 0;
		}
	}

	// Check cols
	for(int col = 0; col < 9; col++) {
		if(!check_col(board, col)) {
			return 0;
		}
	}

	// Check squares
	for(int row = 0; row < 3; row++) {
		for(int col = 0; col < 3; col++) {
			if(!check_square(board, row, col)) {
				return 0;
			}
		}
	}

	return 1;
}

int fill_board(int board[9][9]) {
	// populate a duplicate board so the passed in one doesn't get changed
	int new_board[9][9];
	for(int row = 0; row < 9; row++) {
		for(int col = 0; col < 9; col++) {
			new_board[row][col] = board[row][col];
		}
	}


	for(int row = 0; row  < 9; row ++) {
		for(int col = 0; col < 9; col++) {
			// find the first empty box
			if(board[row][col] == 0) {
				// try every digit
				for(int insert = 1; insert <= 9; insert++) {
					new_board[row][col] = insert;

					// make sure this digit isn't already a duplicate
					if(check_set(new_board[row]) && 
                                           check_col(new_board, col) && 
                                           check_square(new_board, row / 3, col / 3)) {
						if( fill_board(new_board) ) {
							return 1;
						}
					}
				}
				return 0;
			}
		}
	}

	// No 0s, the board is full
	if( check_board(new_board) ) {
		print(new_board);
		return 1;
	}
}

void process_board() {
	int  board[9][9];
	char line[10];

	//read in the board as ints, replacing '_' with 0
	for(int row = 0; row < 9; row++) {
		scanf("%s", line);
		for(int col = 0; col < 9; col++) {
			if(line[col] == '_') {
				board[row][col] = 0;
			} else {
				// convert from char to int
				board[row][col] = line[col] - '0';
			}
		}
	}

	fill_board(board);
}

int main() {
	int num_tests;
	scanf("%d", &num_tests);

	for(int i = 0; i < num_tests; i++) {
		process_board();
	}
}