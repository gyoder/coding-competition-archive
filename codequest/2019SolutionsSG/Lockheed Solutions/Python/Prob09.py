# Recommended imports for all problems
# Some problems may require more
import sys
import math
import string
import re

with open("Prob09.in.txt") as inputfile:    # Open the input file
        # Always start with reading in the number
        # of test cases from standard input. The
        # rstrip() method removes the lingering newline
        cases = int(inputfile.readline().rstrip())
        hours = re.compile(".*?([0-9]+)h.*")
        minutes = re.compile(".*?([0-9]+)m.*")
        seconds = re.compile(".*?([0-9]+)s.*")
        # Loop for each test case. This is the last line
        # common to all problems; the content of this
        # loop will change based on the problem solved.
        for caseNum in range(cases):
                data = inputfile.readline().rstrip()
                hourMatch = hours.match(data)
                minMatch = minutes.match(data)
                secMatch = seconds.match(data)
                h = 0
                m = 0
                s = 0
                if hourMatch:
                        h = int(hourMatch.group(1))
                if minMatch:
                        m = int(minMatch.group(1))
                if secMatch:
                        s = int(secMatch.group(1))
                if h < 10:
                        h = "0" + str(h)
                if m < 10:
                        m = "0" + str(m)
                if s < 10:
                        s = "0" + str(s)
                print(str(h) + ":" + str(m) + ":" + str(s))
