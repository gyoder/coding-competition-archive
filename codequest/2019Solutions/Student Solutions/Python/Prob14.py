import sys
import math
import string

def getIn():
    cases = sys.stdin.read().split('\n')[1:-1]
    ret = []
    for case in cases:
        ret.append(case.rstrip())

    return ret

def convert(code, calph):
    alph = list("abcdefghijklmnopqrstuvwxyz")
    ret = ''
    for letter in code:
        if letter != ' ':
            ret += calph[alph.index(letter)]
        else:
            ret += ' '
    return ret


lines = getIn()


def findval(val, cities):
    for city in cities.keys():
        newval = cities[city]

        if newval == val:
            return newval, city

    



x = 0

while True:
    try:
        numcities = lines[x]
    except:
        break
    x += 1

    cities = {}
    journey = []

    for y in range(int(numcities)):
        line = lines[x + y]
        args = line.split(' ')
        cities[args[0]] = args[1]

    for city in cities.keys():
        val = cities[city]

        if val not in cities.keys():
            current = city
            journey.append(val)


    for z in range(0, y):
        newval, city = findval(current, cities)
        journey.append(newval)
        current = city

    journey.append(city)

    for city in journey:
        print(city)

    x += y + 1

    
            

        


