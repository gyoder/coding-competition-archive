import sys
import math
import string

with open("Prob11.in.txt") as inputfile:    # Open the input file
        cases = int(inputfile.readline().rstrip())
        for caseNum in range(cases):
                bitCount = int(inputfile.readline().rstrip())
                maximum = 2 ** bitCount
                for i in range(maximum):
                        remainingValue = i
                        for b in range(bitCount):
                                if remainingValue >= (2 ** (bitCount - b - 1)):
                                        print("1", end="")
                                        remainingValue -= (2 ** (bitCount - b - 1))
                                else:
                                        print("0", end="")
                        print("")
