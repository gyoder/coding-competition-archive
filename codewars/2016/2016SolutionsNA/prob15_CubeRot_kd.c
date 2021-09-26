// CodeWars 2016
//  Cube Rotation
// The cube has six sides and here are the starting colors for each face of the cube.
// Front:  Green
// Left:   Orange
// Right:  Red
// Back:   Blue
// Up:    White
// Down:  Yellow
//
// A move is considered a 90 degree clockwise rotation of one face of the cube.

#include <stdio.h>

char F[] = "GGGG";
char L[] = "OOOO";
char R[] = "RRRR";
char B[] = "BBBB";
char U[] = "WWWW";
char D[] = "YYYY";

void printFront()
{
    printf("%c %c\n", F[0], F[1]);
    printf("%c %c\n", F[2], F[3]);
    printf("\n");
}

void printAll()
{
    printf("%c %c\n", U[0], U[1]);
    printf("%c %c\n", U[2], U[3]);
    printf("%c %c  %c %c  %c %c  %c %c\n", 
           F[0], F[1], R[0], R[1], B[0], B[1], L[0], L[1]);
    printf("%c %c  %c %c  %c %c  %c %c\n", 
           F[2], F[3], R[2], R[3], B[2], B[3], L[2], L[3]);
    printf("%c %c\n", D[0], D[1]);
    printf("%c %c\n", D[2], D[3]);
    printf("\n");
}
main(argc,argv) int argc; char **argv; {
    char tmp,tmp2;
    char buf[10];

    //printAll(); 
    printFront();

    while(gets(buf),buf[0]!='.') {
        printf("%c\n", buf[0]); 
        switch (buf[0]){
        case 'F': // Rotate Front - top is Up
            tmp=F[0];F[0]=F[2];F[2]=F[3];F[3]=F[1];F[1]=tmp;
            tmp=U[2];tmp2=U[3]; U[2]=L[3];U[3]=L[1]; L[3]=D[1];L[1]=D[0];
            D[0]=R[2];D[1]=R[0]; R[0]=tmp;R[2]=tmp2;
            break;
        case 'L': // Rotate Left - top is Up
            tmp=L[0];L[0]=L[2];L[2]=L[3];L[3]=L[1];L[1]=tmp;
            tmp=U[0];tmp2=U[2]; U[0]=B[3];U[2]=B[1]; B[3]=D[0];B[1]=D[2];
            D[0]=F[0];D[2]=F[2]; F[0]=tmp;F[2]=tmp2;
            break;
        case 'R': // Rotate Right - top is Up
            tmp=R[0];R[0]=R[2];R[2]=R[3];R[3]=R[1];R[1]=tmp;
            tmp=U[3];tmp2=U[1]; U[3]=F[3];U[1]=F[1]; F[3]=D[3];F[1]=D[1];
            D[3]=B[0];D[1]=B[2]; B[0]=tmp;B[2]=tmp2;
            break;
        case 'B': // Rotate Back - top is Up
            tmp=B[0];B[0]=B[2];B[2]=B[3];B[3]=B[1];B[1]=tmp;
            tmp=U[1];tmp2=U[0]; U[1]=R[3];U[0]=R[1]; R[3]=D[2];R[1]=D[3];
            D[2]=L[0];D[3]=L[2]; L[0]=tmp;L[2]=tmp2;
            break;
        case 'U': // Rotate Upper - top is Back
            tmp=U[0];U[0]=U[2];U[2]=U[3];U[3]=U[1];U[1]=tmp;
            tmp=B[1];tmp2=B[0]; B[1]=L[1];B[0]=L[0]; L[1]=F[1];L[0]=F[0];
            F[1]=R[1];F[0]=R[0]; R[1]=tmp;R[0]=tmp2;
            break;
        case 'D': // Rotate Down - top is Front
            tmp=D[0];D[0]=D[2];D[2]=D[3];D[3]=D[1];D[1]=tmp;
            tmp=F[2];tmp2=F[3]; F[2]=L[2];F[3]=L[3]; L[2]=B[2];L[3]=B[3];
            B[2]=R[2];B[3]=R[3]; R[2]=tmp;R[3]=tmp2;
            break;
        }
        //printAll(); 
        printFront();
    } 
}
