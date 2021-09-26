#include <stdio.h>
#include <math.h>

int main() {

    double earth_circumference;
    earth_circumference = 40075;

    int num_inputs;

    scanf("%d", &num_inputs);
    
    double earth_radius;
    earth_radius = earth_circumference/2.0/M_PI;

    double radius;
    double circumference;
    double altitude;
    
    int i;
    for (i = 0; i < num_inputs; i++) {

        scanf("%lf", &altitude);
        radius = earth_radius + altitude;

        circumference = 2.0*M_PI*radius;
        printf("%.1f\n", round(circumference*10.0)/10.0);
    }
}
