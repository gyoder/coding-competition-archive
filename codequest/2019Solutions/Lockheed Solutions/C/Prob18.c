#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

int main()
{
    int testCases;
    scanf("%d\n", &testCases);

    for(int testcase = 0; testcase < testCases; testcase++) {
        char string[100];
        gets(string);

        double real;
        double imag;
        sscanf(string, "%lf %lf\n", &real, &imag);

        complex c = real+I*imag;
        complex z = 0;
        int n = 0;

        while ( (cabsl(z) <= 100) && (n < 51) ) {
            n++;
            z = z*z + c;
        }

        char* space = strstr(string, " ");
        space[0] = '+';

        printf("%si ", string);

        if (n <= 10)
            printf("RED");
        else if (n <= 20)
            printf("ORANGE");
        else if (n <= 30)
            printf("YELLOW");
        else if (n <= 40)
            printf("GREEN");
        else if (n <= 50)
            printf("BLUE");
        else
            printf("BLACK");
        printf("\n");
    }
}
