#Whitney M. Holland
#16 March 2019
#Code Quest: Caught Speeding
"""
Run program from commandline with: python sumItUp.py < input.txt > output.txt
"""
import sys

with open("Prob04.in.txt") as inputfile:    # Open the input file
	#read in whole file
	lines = inputfile.readlines()

testCases = int(lines[0])

#read each line starting w/ second line
i = 1
while i <= testCases:
	lineInfo = lines[i].split(" ")
	var1 = int(lineInfo[0])
	var2 = str(lineInfo[1]).rstrip().lower()

	if var2 == "true":
		var1 -= 5

	if var1 <= 60:
		print("no ticket")
	elif var1 <= 80:
		print("small ticket")
	elif var1 > 80:
		print("big ticket")
		
	i += 1



