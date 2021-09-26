import sys
import math
import string
import re


cases = int(sys.stdin.readline().rstrip())

for caseNum in range(cases):
        x = (sys.stdin.readline().rstrip())
        
        line = x.split("\n")
        
        for i in line:
                x = str(i)
                r = re.split(r'[\s]', x)
                a,b = r

                if int(a) == int(b):
                        c = int(a) * 4
                else:
                        c = int(a) + int(b)
                        
                print(c)

        
                        


          
        


                
