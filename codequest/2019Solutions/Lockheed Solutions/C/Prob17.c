#include <stdio.h>
#include <math.h>
#include <string.h>



int main() {

    char input[1024];
    int num_test_cases;
    fgets(input, 1024, stdin);
    sscanf(input, "%d", &num_test_cases);

    int i;
    for (i = 0; i < num_test_cases; i++) {

        int num_generations;
        fgets(input, 1024, stdin);
        sscanf(input, "%d", &num_generations);

        char board[10][10];
        char next_board[10][10];
        int j;
        for (j = 0; j < 10; j++) {
            fgets(input, 1024, stdin);
            sscanf(input, "%s", board[j]);
        }

        for (j = 0; j < num_generations; j++) {
            int k;
            for (k = 0; k < 10; k++) {
                int l;
                for (l = 0; l < 10; l++) {
                    int adjacent_live_cells;
                    adjacent_live_cells = 0;
                    int m;
                    for (m = -1; m <= 1; m++) {
                        int n;
                        for (n = -1; n <= 1; n++) {
                            if ((m != 0 || n != 0) && (k+m >= 0 && l+n >= 0) && (k+m < 10 && l+n < 10)) {
                                if (board[k+m][l+n] == '1') {
                                    adjacent_live_cells += 1;
                                }
                            }
                        }
                    }
                    if (adjacent_live_cells == 3) {
                        next_board[k][l] = '1';
                    }
                    else if (adjacent_live_cells < 2 || adjacent_live_cells > 3) {
                        next_board[k][l] = '0';
                    }
                    else if (board[k][l] == '1') {
                        next_board[k][l] = '1';
                    }
                    else {
                        next_board[k][l] = '0';
                    }
                }
            }
            for (k = 0; k < 10; k++) {
                int l;
                for (l = 0; l < 10; l++) {
                    board[k][l] = next_board[k][l];
                }
            }
        }
        for (j = 0; j < 10; j++) {
            int k;
            for (k = 0; k < 10; k++) {
                printf("%c", next_board[j][k]);
            }
            printf("\n");
        }
    }    
}
