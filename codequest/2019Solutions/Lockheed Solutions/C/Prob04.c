#include <stdio.h>
#include <math.h>
#include <string.h>



int main() {

    int num_test_cases;
    scanf("%d", &num_test_cases);

    int i;
    for (i = 0; i < num_test_cases; i++) {
    
        int speed;
        char birthday[10];
        scanf("%d %s", &speed, birthday);

        int bd;
        bd = 0;
        if (strcmp(birthday, "true") == 0) {bd = 5;}
  
        if (speed <= 60+bd) {printf("no ticket\n");}
        else if (speed <= 80+bd) {printf("small ticket\n");}
        else {printf("big ticket\n");}
    }
}
