#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>


int main() {

    char input[1024];
    fgets(input, 1024, stdin);
    int num_test_cases;
    sscanf(input, "%d", &num_test_cases);

    int i;
    for (i = 0; i < num_test_cases; i++) {

        fgets(input, 1024, stdin);
        char gorilla_one[8];
        char gorilla_two[8];
        sscanf(input, "%s %s", gorilla_one, gorilla_two);

        if (strcmp(gorilla_one, gorilla_two)) {
            printf("false");
        }
        else {
            printf("true");
        }
        printf("\n");
    }
}
