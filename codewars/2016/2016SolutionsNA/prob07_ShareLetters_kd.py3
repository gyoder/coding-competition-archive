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
# BDSU

import sys

def countLetter(word,letter):
    wordLen=len(word)
    letterCount=0;
    for i in range(wordLen) :
        if (word[i]==letter):
            letterCount=letterCount+1
    return letterCount

def min (a,b):
    if (a<b):
        return a
    return b

All='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
#-----------------------
#Main program starts here.
lineCount = int(sys.stdin.readline().rstrip('\n'))
for i in range(lineCount):
    line = sys.stdin.readline().rstrip('\n').rstrip(' ');
    words = line.split();
    for c in range(26):
        minC=min(countLetter(words[0],All[c]), countLetter(words[1],All[c]))
        minC=min(minC, countLetter(words[2],All[c]))
#        print('Minimum', All[c], minC)
        for i in range(minC) :
            print(All[c],sep='',end='')
    print("") #new Line

