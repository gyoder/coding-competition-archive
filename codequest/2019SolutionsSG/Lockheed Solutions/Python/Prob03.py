#Whitney M. Holland
#16 March 2019
#Code Quest: Goofy Gorillas
"""
Run program from commandline with: python sumItUp.py < input.txt > output.txt
"""
import sys

with open("Prob03.in.txt") as inputfile:    # Open the input file
	#read in whole file...
	lines = inputfile.readlines()
testCases = int(lines[0])

#read each line starting w/ second line...
i = 1
while i <= testCases:
	lineInfo = lines[i].split(" ")
	var1 = str(lineInfo[0]).rstrip()
	var2 = str(lineInfo[1]).rstrip()
	if var1 == var2:
		print("true")
	else:
		print("false")
	i += 1



