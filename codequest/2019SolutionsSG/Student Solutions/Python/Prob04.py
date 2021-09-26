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
    vals = line.split(' ')
    speed = int(vals[0])
    if vals[1] == 'true':
        speed -= 5

    if speed <= 60:
        print('no ticket')
    elif speed <= 80:
        print('small ticket')
    else:
        print('big ticket')
