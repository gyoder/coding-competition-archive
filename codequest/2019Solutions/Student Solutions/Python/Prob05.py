import sys
import math
import string

def possible(small, large, target):
    small = int(small)
    large = int(large)
    target = int(target)
    total = 0
    while large > 0 and total < target:
        total += 5
        large -= 1
    if total > target:
        total -= 5
        large += 1
    while small > 0 and total < target:
        total += 1
        small -= 1
    if total == target:
        return "true"
    else:
        return "false"

data=[]
cases = int(sys.stdin.readline().rstrip())
for caseNum in range(cases):
    data.append(sys.stdin.readline().rstrip().split())
for i in range(0, len(data)):
    print(possible(data[i][0], data[i][1], data[i][2]))
