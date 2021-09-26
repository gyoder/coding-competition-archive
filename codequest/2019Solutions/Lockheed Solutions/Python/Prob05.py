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
        small = int(data[0])
        large = int(data[1])
        goal = int(data[2])
        while large > 0 and goal >= 5:
                large -= 1
                goal -= 5
        while small > 0 and goal >= 1:
                small -= 1
                goal -= 1
        if goal == 0:
                print("true")
        else:
                print("false")
