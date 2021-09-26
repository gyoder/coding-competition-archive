#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <string.h>
using namespace std;

int main()
{
   string testCases;
   char bstr1[10];
   char bstr2[10];

   getline(cin, testCases);

   for (int i = 0; i < atoi(testCases.c_str()); i ++)
   {
      string str;

      getline(cin, str);
      
      sscanf(str.c_str(), "%s %s", bstr1, bstr2);

      if ((!strcmp(bstr1, "true") && !strcmp(bstr2, "true")) || 
          (!strcmp(bstr1, "false") && !strcmp(bstr2, "false")))
      {
         cout << "true" << '\n';
      }
      else
      {
         cout << "false" << '\n';
      }
   }
}