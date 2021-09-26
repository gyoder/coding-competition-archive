import sys 

def get_color(n):
    if n<=10:
        return "RED"    
    if n<=20:
        return "ORANGE"
    if n<=30:
        return "YELLOW"    
    if n<=40:
        return "GREEN"
    if n<=50:
        return "BLUE"
    return "BLACK"
    
def main():
    with open("Prob18.in.txt") as inputfile:    # Open the input file
        cases = int(inputfile.readline().rstrip()) 
        
        for caseNum in range(cases): 
            line=inputfile.readline().rstrip()
            a,b = map(float,line.split())
            c = complex(a,b)
            z = complex(0,0)
            n = 0
            
            line=line.replace(' ','+')+'i '
                                            
            while (abs(z)<=100 and n<51):
                n = n+1
                z = z*z+c

            print(line+get_color(n)) 

main()
