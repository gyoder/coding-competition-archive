#!/usr/bin/env python

#CodeWars 2016
#
#Input
#Each line of input has three integers: the Length, Width and Depth of the block. The input ends with three zeroes.
#5 6 7
#10 11 12
#8 10 12
#0 0 0
#Output
#The program must print the classification for each block. Capitalize only MORE, LESS, or PERFECT as appropriate.
#A 5x6x7 block is MORE than Perfect.
#A 10x11x12 block is LESS than Perfect.
#A 8x10x12 block is PERFECT.

import sys


#-----------------------
#Main program starts here.
for line in sys.stdin:
    a,b,c = line.split();
    a=int(a)
    b=int(b)
    c=int(c)
    if (a==0):
        exit()
    inside=(a-2)*(b-2)*(c-2)
    total=a*b*c
    outside = total-inside
    print ("A ",a,"x",b,"x",c," block is ",sep='',end='')
    if (outside==inside):
        print("PERFECT.")
    else:
        if (outside<inside):
            print("LESS than perfect.")
        else:
            print("MORE than perfect.")

