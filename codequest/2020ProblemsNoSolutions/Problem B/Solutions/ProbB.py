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
	# For problem B, we need to read in our data
	dataString = sys.stdin.readline()
	data = dataString.split(":")
	# then we need to convert it to numbers
	velocity = float(data[0])
	distance = float(data[1])
	# calculate time to crash
	if (velocity == 0.0):
		print("SAFE")
	else:
		time = distance / velocity
		# respond accordingly
		if (time <= 1.0):
			print("SWERVE")
		elif (time <= 5.0):
			print("BRAKE")
		else:
			print("SAFE")
