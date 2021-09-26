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

        char sentence[128];
        fgets(sentence, 128, stdin);
        
        int j;
        for (j = 0; sentence[j]; j++) {
            sentence[j] = tolower(sentence[j]);
        }
        printf("%s", sentence);
    }
}
