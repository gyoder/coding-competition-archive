import sys
import math
import string


cases = int(sys.stdin.readline().rstrip())
for caseNum in range(cases):
    data=[]
    output = []
    maximum = 0
    minimum = 999999
    for case2 in range(int(sys.stdin.readline().rstrip())):
        new = sys.stdin.readline().rstrip()
        data.append(new)
        if float(new) < minimum:
            minimum = float(new)
        if float(new) > maximum:
            maximum = float(new)
    for i in range(0, len(data)):
        output.append(int(round(((float(data[i])-minimum)/(maximum - minimum))*255, 0)))
    for a in output:
        print(a)
