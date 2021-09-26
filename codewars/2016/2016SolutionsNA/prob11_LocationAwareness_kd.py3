#!/usr/bin/env python

#CodeWars 2016
#
#  Location Awareness
# 
# For this problem, you will write a trilateration algorithm (explained below) 
# for an autonomous robot using signals from three tow-ers positioned around 
# a square arena. The arena is an integer grid with walls at 
# x=100, y=100, x=-100, and y=-100. The robot may be positioned anywhere 
# within the arena. Tower 1 is located at x,y position 0,100, 
# tower 2 at -100,-100, and tower 3 at 100,-100.
#
# Here's how the system works: the towers broadcast distinct signals that 
# the robot can receive. The towers are all powered by one common battery. 
# When the robot is near a tower, the signal strength is high, but the 
# farther the robot is from the tower, the weak-er the signal. 
# The strength of a tower's signal is given by the following equation:
# s = P / ( d * d )
# The variable P is the transmission power and d is the distance from the 
# tower to the robot. When the battery is fully charged the signal is very 
# strong. But over time, as the battery's energy is used, the signal power 
# is reduced. So P is the same for each tower, but it changes over time. 
# Also, the robot has no direct way to measure P. So it is not possible 
# to make an exact calculation for the distance to a tower using the signal 
# strength. You'll have to think of how to use all three signals to solve 
# the problem. The only math you need to know is that the distance between 
# two points (x0,y0) and (x1,y1) is given by this equation:
# d = sqrt( (x0-x1)^2 + (y0-y1)^2 ) 
# Use the signals from the three towers to determine the robot's 
# location on the grid.
# 
# Each line of input has three floating-point numbers separated by one or 
# more spaces. These numbers are the signal strengths from 
# towers 1, 2, and 3, in that order. The input ends with three zeros.
# 5.432 2.716 2.716
# 6.733 0.956 1.284
# 501.345 2.102 1.878
# 2.207 2.644 662.852
# 0 0 0
# Output
# For each input line, the program must print the exact integer 
# x and y location of the robot.
# 0 0
# 21 35
# -14 99
# 93 -90

import sys

def max (a,b):
    if a>b:
        return a
    return b

# Set up all the constants
minX=-100
maxX=100
minY=-100
maxY=100
# # within the arena. Tower 1 is located at x,y position 0,100, 
# tower 2 at -100,-100, and tower 3 at 100,-100.
x0=0
y0=100
x1=-100
y1=-100
x2=100
y2=-100

#-----------------------
#Main program loop starts here.
for line in sys.stdin:
    a,b,c = line.split(); # Read in the signal strengths from each tower
    a=float(a)
    b=float(b)
    c=float(c)
    a2 = a*a   # We're going to only work with distance squared
    b2 = b*b
    c2 = c*c 
    if (a==0):
        exit()
    #print("A, B, C: ", a, b, c)
    # Loop through all locations and calculate the square distances (easier)
    # Then compare the provided lengths and see if they all have the same ratio difference
    found = 0
    minPowerDiff = a * 40000  # Start with maximum distance
    for i in range(minX, maxX):
        if found==1:
            exit()
        for j in range (minY, maxY):
            if found==1:
                exit()
            d0sq = (x0-i)*(x0-i) + (y0-j)*(y0-j)
            d1sq = (x1-i)*(x1-i) + (y1-j)*(y1-j)
            d2sq = (x2-i)*(x2-i) + (y2-j)*(y2-j)
            # s = P / ( d * d ), so P = s*(d-squared)
            P0 = a*d0sq
            P1 = b*d1sq
            P2 = c*d2sq
            newPowerDiff = max(abs(P1-P0), max(abs(P2-P0), abs(P2-P1)))
            if (newPowerDiff < minPowerDiff):
                newX=i
                newY=j
                minPowerDiff = newPowerDiff
    #Now print the location of the lowest difference in power values
    print(newX, newY)
