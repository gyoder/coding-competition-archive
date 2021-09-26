# Recommended imports for all problems
# Some problems may require more
import sys
import math
import string

with open("Prob01.in.txt") as inputfile:    # Open the input file
	# Always start with reading in the number
	# of test cases from standard input. The
	# rstrip() method removes the lingering newline
	cases = int(inputfile.readline().rstrip())
	# Loop for each test case. This is the last line
	# common to all problems; the content of this
	# loop will change based on the problem solved.
	for caseNum in range(cases):
	        original = inputfile.readline().rstrip()
	        print(original.lower())
