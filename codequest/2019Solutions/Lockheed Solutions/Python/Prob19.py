# Recommended imports for all problems
# Some problems may require more
import sys
import math
import string

# 33.8 minutes

# Always start with reading in the number
# of test cases from standard input. The
# rstrip() method removes the lingering newline
cases = int(sys.stdin.readline().rstrip())
# Loop for each test case. This is the last line
# common to all problems; the content of this
# loop will change based on the problem solved.
for caseNum in range(cases):
        addresses = int(sys.stdin.readline().rstrip())
        binaries = list(range(addresses))
        for i in range(addresses):
                numbers = sys.stdin.readline().rstrip().split('.')
                binary = ''
                for j in range(4):
                        number = int(numbers[j])
                        binary += format(number, '08b')
                binaries[i] = binary;
        foundMismatch = False
        firstMismatch = 32
        outputBinary = ''
        for bit in range(32):
                if foundMismatch:
                       outputBinary += '0'
                else:
                        referenceBit = binaries[0][bit]
                        for i in range(1, addresses):
                                if referenceBit != binaries[i][bit]:
                                        foundMismatch = True
                                        firstMismatch = bit
                                        break
                        if foundMismatch:
                                outputBinary += '0'
                        else:
                                outputBinary += referenceBit
        outputRange = str(int(outputBinary[0:8], base=2)) + '.'
        outputRange += str(int(outputBinary[8:16], base=2)) + '.'
        outputRange += str(int(outputBinary[16:24], base=2)) + '.'
        outputRange += str(int(outputBinary[24:32], base=2))
        outputRange += '/' + str(firstMismatch)
        print(outputRange)
                               
                               
