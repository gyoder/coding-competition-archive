import sys
import math
import string

cases = int(sys.stdin.readline().rstrip())
for caseNum in range(cases):
        bitCount = int(sys.stdin.readline().rstrip())
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
