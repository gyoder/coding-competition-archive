#include <stdio.h>
#include <math.h>
#include <string.h>



int main() {

    char letters[26] = "abcdefghijklmnopqrstuvwxyz";

    char input[1024];
    fgets(input, 1024, stdin);
    int num_test_cases;
    sscanf(input, "%d", &num_test_cases);

    int i;
    for (i = 0; i < num_test_cases; i++) {
        int message_key;
        fgets(input, 1024, stdin);
        sscanf(input, "%d", &message_key);
        char message[1024];
        fgets(message, 1024, stdin);

        int j;
        for (j = 0; j < strlen(message)-1; j++) {
            if (message[j] == ' ') {
                continue;
            }
            int k;
            for (k = 0; k < 26; k++) {
                if (message[j] == letters[k]) {
                    int temp;
                    temp = (k-message_key) % 26;
                    if (temp < 0) {
                        temp += 26;
                    }
                    message[j] = letters[temp];
                    break;
                }
            }
        }
        printf("%s", message);
    }
}
