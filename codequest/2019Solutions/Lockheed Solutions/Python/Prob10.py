# Recommended imports for all problems
# Some problems may require more
import sys
import math
import string

# Always start with reading in the number
# of test cases from standard input. The
# rstrip() method removes the lingering newline
cases = int(sys.stdin.readline().rstrip())
alphabet = 'abcdefghijklmnopqrstuvwxyz';
# Loop for each test case. This is the last line
# common to all problems; the content of this
# loop will change based on the problem solved.
for caseNum in range(cases):
        shift = int(sys.stdin.readline().rstrip())
        ciphertext = sys.stdin.readline().rstrip()
        for i in range(len(ciphertext)):
                cipherchar = ciphertext[i]
                if cipherchar == ' ':
                        print(" ", end="")
                else:
                        index = alphabet.index(cipherchar)
                        index -= shift
                        if index < 0:
                                index += 26
                        if index >= 26:
                                index -= 26
                        plainchar = alphabet[index]
                        print(plainchar, end="")
        print("")
