# Recommended imports for all problems
# Some problems may require more
import sys
import math
import string

# Always start with reading in the number
# of test cases from standard input. The
# rstrip() method removes the lingering newline
cases = int(sys.stdin.readline().rstrip())
# Loop for each test case. This is the last line
# common to all problems; the content of this
# loop will change based on the problem solved.
for caseNum in range(cases):
        data = sys.stdin.readline().rstrip().split(" ")
        if data[0] == data[1]:
                print(int(data[0]) * 4)
        else:
                print(int(data[0]) + int(data[1]))
