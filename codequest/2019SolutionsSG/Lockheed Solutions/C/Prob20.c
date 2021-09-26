#include <stdio.h>
#include <math.h>
#include <string.h>

struct bird {
    char taxonomic_family[32];
    float length;
    float width;
    float wingspan;
    float wing_angle;
    float distance;
};


int main() {

    int num_test_cases;
    scanf("%d", &num_test_cases);

    int i;
    for (i = 0; i < num_test_cases; i++) {

        int num_known;
        int num_unknown;
        scanf("%d %d", &num_known, &num_unknown);

        struct bird known[num_known];
        struct bird unknown[num_unknown];
        int j;
        for (j = 0; j < num_known; j++) {
            scanf("%s %f %f %f %f", known[j].taxonomic_family, &known[j].length, &known[j].width, &known[j].wingspan, &known[j].wing_angle);
        }
        for (j = 0; j < num_unknown; j++) {
            scanf("%f %f %f %f", &unknown[j].length, &unknown[j].width, &unknown[j].wingspan, &unknown[j].wing_angle);
        }

        int num_accipitridae;
        int num_passeridae;
        int num_cathartidae;
        for (j = 0; j < num_unknown; j++) {
            int k;
            struct bird temp;
            for (k = 0; k < num_known; k++) {
                known[k].distance = sqrt(pow(unknown[j].length - known[k].length, 2) + pow(unknown[j].width - known[k].width, 2) + pow(unknown[j].wingspan - known[k].wingspan, 2) + pow(unknown[j].wing_angle - known[k].wing_angle, 2));
            }
            for (k = 0; k < num_known-1; k++) {
                int l;
                for (l = 0; l < num_known-1; l++) {
                    if (known[l].distance > known[l+1].distance) {
                        temp = known[l];
                        known[l] = known[l+1];
                        known[l+1] = temp;
                    }
                }
            }
            num_accipitridae = 0;
            num_passeridae = 0;
            num_cathartidae = 0;
            for (k = 0; k < num_known; k++) {
                if (strcmp(known[k].taxonomic_family, "Accipitridae") == 0) {
                    num_accipitridae += 1;
                    if (num_accipitridae == 3) {
                        printf("Accipitridae\n");
                        break;
                    }
                }
                else if (strcmp(known[k].taxonomic_family, "Passeridae") == 0) {
                    num_passeridae += 1;
                    if (num_passeridae == 3) {
                        printf("Passeridae\n");
                        break;
                    }
                }
                else {
                    num_cathartidae += 1;
                    if (num_cathartidae == 3) {
                        printf("Cathartidae\n");
                        break;
                    }
                } 
            }
        }
    }
}
