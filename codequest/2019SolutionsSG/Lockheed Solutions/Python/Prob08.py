import sys
import math
import string

with open("Prob08.in.txt") as inputfile:    # Open the input file
        cases = int(inputfile.readline().rstrip())
        for caseNum in range(cases):
                testCaseData = inputfile.readline().rstrip().split(" ")
                targetRow = int(testCaseData[0])
                targetCol = int(testCaseData[1])
                for row in range(0,20):
                        for col in range(0,20):
                                if col != 0:
                                        print(" ", end="")
                                level = 10
                                rowDiff = abs(targetRow - row)
                                colDiff = abs(targetCol - col)
                                if row == targetRow and col == targetCol:
                                        level = 100
                                elif rowDiff <= 1 and colDiff <= 1:
                                        level = 50
                                elif rowDiff <= 2 and colDiff <= 2:
                                        level = 25
                                print(level, end="")
                        print("")
