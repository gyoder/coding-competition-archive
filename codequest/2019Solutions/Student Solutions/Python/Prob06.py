import sys
import math
import string

def getIn():
    cases = sys.stdin.read().split('\n')[1:-1]
    ret = []
    for case in cases:
        ret.append(case.rstrip())

    return ret


lines = getIn()
for line in lines:
    altitude = int(line)

    radius = (40075/3.141592653589793238462) / 2

    orbitr = radius + altitude

    new = orbitr * 2

    print(round((new * 3.1415926535)*10)/10)


