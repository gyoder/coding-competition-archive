# Recommended imports for all problems
# Some problems may require more
import sys
import math
import string
# New imports for this problem
from datetime import date
from datetime import timedelta

def roundHalfUp(original):
	multiplied = original * 1000.0;
	floored = math.floor(multiplied)
	remainder = multiplied - floored
	if remainder >= 0.5:
		floored += 1
	rounded = str(floored / 1000.0)
	while len(rounded) - rounded.index('.') < 4:
		rounded += '0'
	return rounded

today = date(2019, 4, 27)

with open("Prob01.in.txt") as inputfile:    # Open the input file
        # Always start with reading in the number
        # of test cases from standard input. The
        # rstrip() method removes the lingering newline
        cases = int(inputfile.readline().rstrip())
        # Loop for each test case. This is the last line
        # common to all problems; the content of this
        # loop will change based on the problem solved.
        for caseNum in range(cases):
                specs = inputfile.readline().rstrip().split(" ")
                numFiles = int(specs[0])
                capacity = float(specs[1]) * 1000000
                sizes = {}
                names = {}
                scores = []
                for i in range(numFiles):
                        fileData = inputfile.readline().rstrip().split(" ")
                        dateValues = fileData[0].split("/")
                        fileDate = date(int(dateValues[2]), int(dateValues[1]), int(dateValues[0]))
                        ageInDays = (today - fileDate).days
                        if fileData[2] == 'PM':
                                ageInDays -= 0.5
                        size = int(fileData[3])
                        name = fileData[4]
                        score = (ageInDays * (size / 1000.0))
                        sizes[name] = size
                        names[score] = name
                        scores.append(score)
                scores.sort()
                target = capacity / 4
                while target > 0:
                        highScore = scores.pop()
                        name = names[highScore]
                        size = sizes[name]
                        target -= size
                        print(name + ' ' + roundHalfUp(highScore))
