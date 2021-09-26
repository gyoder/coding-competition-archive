#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int i;
    int inp1,inp2;
    scanf("%d",&i);
    while(i>0){
        scanf("%d %d",&inp1,&inp2);
        if (inp1==inp2)
        {
            printf("%d\n",(inp1+inp2)*2);
        }
        else
        {
            printf("%d\n",inp1+inp2);
        }
        i=i-1;
    }
}
