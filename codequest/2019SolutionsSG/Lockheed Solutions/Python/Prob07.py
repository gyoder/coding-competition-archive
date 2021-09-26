#Whitney M. Holland
#17 March 2019
#Code Quest: Image Compression
"""
Run program from commandline with: python imageCompression.py < input.txt > output.txt
"""
import sys

with open("Prob07.in.txt") as inputfile:    # Open the input file
	#read in whole file
	lines = inputfile.readlines()
testCases = int(lines[0])

#read each line starting w/ second line
i = 1
j = 1

while i <= testCases:
	x = int(lines[j])
	j += 1
	k = j + x
	outBrightList = []
	while j < k:
		newValue = lines[j].rstrip()
		outBrightList.append(newValue)
		j += 1
	minBright = min(float(a) for a in outBrightList)
	maxBright = max(float(a) for a in outBrightList)
	for b in outBrightList:
		b = float(b)
		outValue = round(((b - minBright) / (maxBright - minBright)) * 255)
		print(outValue)	

	i += 1

	