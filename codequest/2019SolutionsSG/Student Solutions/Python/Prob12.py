import sys
import math
import string

cases = int(sys.stdin.readline().rstrip())
for caseNum in range(cases):
    line = sys.stdin.readline().rstrip().split()
    doors = line[0]
    rounds = line[1]
    toOpen = line[2]

    doorsOpen = 0
    chance = 100/int(doors)
    totalChance = 100

    for i in range(int(rounds)):
        doorsOpen += int(toOpen)
        totalChance -= float(chance)
        doorSwap = int(doors) - int(doorsOpen) - (i+1)
        chance = totalChance / doorSwap

    chance = round(chance, 2)
    if len(str(chance).split(".")[-1])<2:
        chance = str(chance) + "0" 
    print(str(chance) + "%")
