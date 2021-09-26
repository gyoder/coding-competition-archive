#!/usr/bin/env python

#CodeWars 2016
#
# Queen Ann only likes words that have double-letters, like her name. Write a program that can tell if a word is something that Queen Ann likes.
#Input
#The first line of input specifies how many words the program must read. Each word follows on a separate line. Words are com-posed of upper case English letters.
#7
#KITTENS
#FORKS
#WINTER
#RIDDLES
#TELEVISION
#BOOKS
#COWS
#
#Output
#For each input word, the program must print whether Queen Ann "likes" or "hates" the word.
#likes KITTENS
#hates FORKS
#hates WINTER
#likes RIDDLES
#hates TELEVISION
#likes BOOKS
#hates COWS

import sys

#-----------------------
#Main program starts here.
lineCount = int(sys.stdin.readline().rstrip('\n'))
for i in range(lineCount):
    line = sys.stdin.readline().rstrip('\n').rstrip(' ');
    j = len(line)
    feeling="hates"
    for k in range(j):
        if (line[k-1]==line[k]):
            feeling="likes"
    print(feeling, line)
