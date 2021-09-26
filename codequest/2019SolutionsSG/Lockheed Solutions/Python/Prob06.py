# Recommended imports for all problems
# Some problems may require more
import sys
import math
import string

with open("Prob06.in.txt") as inputfile:    # Open the input file
	# Always start with reading in the number
	# of test cases from standard input. The
	# rstrip() method removes the lingering newline
	cases = int(inputfile.readline().rstrip())
	# Loop for each test case. This is the last line
	# common to all problems; the content of this
	# loop will change based on the problem solved.
	for caseNum in range(cases):
	        altitude = int(inputfile.readline().rstrip());
	        circumference = (2 * math.pi * altitude) + 40075;
	        circumference = round(circumference * 10.0) / 10.0;
	        print(circumference);
