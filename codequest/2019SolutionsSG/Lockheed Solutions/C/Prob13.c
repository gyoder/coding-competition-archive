#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


struct bomb {
    int row;
    int column;
};

struct tile {
    int count;
};

int main() {

    char test_cases[8];
    fgets(test_cases, 8, stdin);
    int num_test_cases;
    sscanf(test_cases, "%d", &num_test_cases);

    int i;
    for (i = 0; i < num_test_cases; i++) {

        char input[128];
        fgets(input, 128, stdin);
        int num_rows;
        int num_columns;
        int num_bombs;
        sscanf(input, "%d %d %d", &num_rows, &num_columns, &num_bombs);

        int j;
        char bomb_input[8];
        struct bomb bombs[num_bombs];
        for (j = 0; j < num_bombs; j++) {
            fgets(bomb_input, 8, stdin);
            sscanf(bomb_input, "%d %d", &bombs[j].row, &bombs[j].column);
        }

        struct tile tiles[num_rows][num_columns];
        for (j = 0; j < num_rows; j++) {
            int k;
            for (k = 0; k< num_columns; k++) {
                tiles[j][k].count = 0;
                int l;
                for (l = 0; l < num_bombs; l++) {
                    if (j == bombs[l].row && k == bombs[l].column) {
                        tiles[j][k].count = -1;
                        break;
                    }
                } 
            }
        }

        for (j = 0; j < num_rows; j++) {
            int k;
            for (k = 0; k < num_columns; k++) {
                if (tiles[j][k].count == -1) {
                    continue;
                }
                int l;
                for (l = -1; l <= 1; l++) {
                    if (j + l < 0 || j + l >= num_rows) {
                        continue;
                    }
                    int m;
                    for (m = -1; m <= 1; m++) {
                        if (k + m < 0 || k + m >= num_columns) {
                            continue;
                        }
                        if (tiles[j+l][k+m].count == -1) {
                            tiles[j][k].count += 1;
                        }
                    }
                }
            }
        }
        for (j = 0; j < num_rows; j++) {
            int k;
            for (k = 0; k < num_columns; k++) {
                if (tiles[j][k].count == -1) {
                    printf("*");
                } else {
                    printf("%d", tiles[j][k].count);
                }
            }
            printf("\n");
        }
    }
}
