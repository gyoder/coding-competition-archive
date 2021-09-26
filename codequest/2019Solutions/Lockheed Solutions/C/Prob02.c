#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


int main() {

    char test_cases[8];
    fgets(test_cases, 8, stdin);
    int num_test_cases;
    sscanf(test_cases, "%d", &num_test_cases);

    int i;
    for (i = 0; i < num_test_cases; i++) {

        char integers[128];
        fgets(integers, 128, stdin);
        int int_one;
        int int_two;
        sscanf(integers, "%d %d", &int_one, &int_two);

        if (int_one == int_two) {
            printf("%d\n", int_one*4);
        }
        else {
            printf("%d\n", int_one + int_two);
        }

    }
}
