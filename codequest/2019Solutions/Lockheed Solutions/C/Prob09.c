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

        char time_string[128];
        fgets(time_string, 128, stdin);

        char gibberish_before[128];
        char gibberish_after[128];
        int hour;
        hour = 0;
        int minute;
        minute = 0;
        int second;
        second = 0;
        char *hour_p;
        char *minute_p;
        char *second_p;
        
        hour_p = strchr(time_string, 'h');
        if (hour_p != NULL) {
            if (hour_p-2 >= time_string) {
                if (isdigit(*(hour_p-2))) {
                    sscanf(hour_p-2, "%d", &hour);
                }
                else {
                    sscanf(hour_p-1, "%d", &hour);
                }
            }
            else {
                sscanf(hour_p-1, "%d", &hour);
            }
        }
        minute_p = strchr(time_string, 'm');
        if (minute_p != NULL) {
            if (minute_p-2 >= time_string) {
                if (isdigit(*(minute_p-2))) {
                    sscanf(minute_p-2, "%d", &minute);
                }
                else {
                    sscanf(minute_p-1, "%d", &minute);
                }
            }
            else {
                sscanf(minute_p-1, "%d", &minute);
            }
        }
        second_p = strchr(time_string, 's');
        if (second_p != NULL) {
            if (second_p-2 >= time_string) {
                if (isdigit(*(second_p-2))) {
                    sscanf(second_p-2, "%d", &second);
                }
                else {
                    sscanf(second_p-1, "%d", &second);
                }
            }
            else {
                sscanf(second_p-1, "%d", &second);
            }
        }

        printf("%02d:%02d:%02d\n", hour, minute, second);
     
    }
}
