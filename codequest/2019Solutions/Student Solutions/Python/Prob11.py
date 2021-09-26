# Recommended imports for all problems
# Some problems may require more
import sys
import math
import string

dictionary={
    0:"0",
    1:"1",
    2:"2",
    3:"3",
    4:"4",
    5:"5",
    6:"6",
    7:"7",
    8:"8",
    9:"9",
    10:"a",
    11:"b",
    12:"c",
    13:"d",
    14:"e",
    15:"f",
    16:"g",
    17:"h",
    18:"i",
    19:"j",
    20:"k",
    21:"l",
    22:"m",
    23:"n",
    24:"o",
    25:"p",
    26:"q",
    27:"r",
    28:"s",
    29:"t",
    30:"u",
    31:"v",
    32:"w",
    33:"x",
    34:"y",
    35:"z",
    36:".",
    37:",",
    38:"/",
    39:";",
    40:'"',
    41:"#",
    42:"[",
    43:"]",
    44:"=",
    45:"-",
    46:"\\",
    47:"`",
    48:"|",
    49:"¬",
    50:"<",
    51:">",
    52:"?",
    53:":",
    54:"@",
    55:"~",
    56:"}",
    57:"{",
    58:"+",
    59:"_",
    60:")",
    61:"(",
    62:"*",
    63:"&",
    64:"^",
    65:"%",
    66:"$",
    67:"£",
    68:"'",
    69:"!",
    70:" ",
    71:"A",
    72:"B",
    73:"C",
    74:"D",
    75:"E",
    76:"F",
    77:"G",
    78:"H",
    79:"I",
    80:"J",
    81:"K",
    82:"L",
    83:"M",
    84:"N",
    85:"O",
    86:"P",
    87:"Q",
    88:"R",
    89:"S",
    90:"T",
    91:"U",
    92:"V",
    93:"W",
    94:"X",
    95:"Y",
    96:"Z",
    97:"☺",
    98:"☻"
}

def findexponent(a, s):
    i=1
    while True:
        if s**i>a:
            ans=i-1
            break
        else:
            i+=1
    return ans

def inttostr(x, b):
    string=""
    x=int(x)
    digits=1+findexponent(x, b)
    for i in range(digits, 0, -1):
        best=0
        for a in dictionary:
            curr=a*b**(i-1)
            if curr<=x:
                if curr>best:
                    best=a
        x=x-best*b**(i-1)
        string+=dictionary[best]
    return string

cases = int(sys.stdin.readline().rstrip())
for caseNum in range(cases):
    numBits = sys.stdin.readline().rstrip().lower()
    for i in range(2**(int(numBits))):
        returned = inttostr(i, 2)
        returned = "0" * (int(numBits)-len(returned)) + returned
        print(returned)
