#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
   int testCases;
   int one;
   int five;
   int target;
   int temp;
   int q;
   int r;
   char *str;

   scanf("%d\n", &testCases);

   for (int i = 0; i < testCases; i ++)
   {    
      scanf("%d %d %d\n", &one, &five, &target);
  
      temp = one + (five * 5);
      if (temp < target)
      {
         printf("false\n");
      }
      else if (temp == target)
      {
         printf("true\n");
      }
      else 
      { 
         q = target / 5;
         r = target % 5;

         if (q > 0)
         {
            if (five >= q)
            {
               if (r == 0)
               {
                  printf("true\n");
               }
               else if (one >= r)
               {
                  printf("true\n");
               }
               else
               {
                  printf("false\n");
               }
            }
            else
            {
               temp = target - (five * 5);
               if (one >= temp)
               {
                  printf("true\n");
               }
               else
               {
                  printf("false\n");
               }
            }
         }
         else if (one >= r)
         {
            printf("true\n");
         }
         else
         {
            printf("false\n");
         }
      }
   }
}