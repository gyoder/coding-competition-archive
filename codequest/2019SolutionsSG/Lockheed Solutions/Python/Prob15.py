import sys 
from fractions import Fraction

def word_hash(text):
    return sum(ord(x)-ord('a')+1 for x in text)

def main():
	with open("Prob15.in.txt") as inputfile:    # Open the input file
	    cases = int(inputfile.readline().rstrip()) 
	    
	    for caseNum in range(cases): 
	        names = inputfile.readline().rstrip().split()
	        dates = list(map(int,inputfile.readline().rstrip().split()))
	        H=Fraction(0,1)
	        for x in range(10):
	            H = (dates[x]+word_hash(names[x])+(x+1)+H)*Fraction(50,147)
	        
	        print(round(H,0)) 
        
main()
