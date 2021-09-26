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
    hours = '00'
    mins = '00'
    seconds = '00'
    
    nums = '01234567890'
    

    num = ''
    for x in range(len(line)):
        if line[x] in nums:
            num += line[x]
        elif line[x] == 's':
            seconds = num
            num = ''
        elif line[x] == 'm':
            mins = num
            num = ''
        elif line[x] == 'h':
            hours = num
            num = ''

    ret = ''
    if len(hours) == 1:
        ret += '0' + hours
    else:
        ret += hours

    ret += ':'

    if len(mins) == 1:
        ret += '0' + mins
    else:
        ret += mins

    ret += ':'

    if len(seconds) == 1:
        ret += '0' + seconds
    else:
        ret += seconds

    print(ret)


