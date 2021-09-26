#!/usr/bin/env python

#CodeWars 2016
#
#Input
#The first line of input indicates the number of word triplets the program must read. Each line after contains three words, and we use that term loosely, separated by one or more spaces. Don't assume there will only be one space between words.
#3
#TEST MEANT TIME
#KINDERGARTEN CHICKENFEATHERS SPECIALITIES
#ABSURD SUBORDINATE DUMBELLS3
#Output
#For each triplet, the program must print all the letters that are shared by all three words. If a letter appears multiple times in each word, then it should also appear multiple times in the output. The letters must be printed in alphabetic order.
#ET
#AEEIT
#BDSU

import sys

#-----------------------
#Main program starts here.
lineCount = int(sys.stdin.readline().rstrip('\n'))
for i in range(lineCount):
    line = sys.stdin.readline().rstrip('\n').rstrip(' ');
    skipStr, letterString = line.split(None, 1)
    j=len(letterString)
    skipCount=int(skipStr)
    for k in range(j):
        if ((k)%skipCount >0):
#           print(k,letterString[k])
            print(letterString[k],sep='', end='')
    print("")
