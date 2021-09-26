import sys 

def main():
    with open("Prob13.in.txt") as inputfile:    # Open the input file
        cases = int(inputfile.readline().rstrip()) 
        
        for caseNum in range(cases): 
            line = inputfile.readline().rstrip()
            R,C,B = map(int,line.split())
            bombs = set()
            for _ in range(B):
                line=inputfile.readline().rstrip()
                x, y = map(int,line.split())
                bombs.add((x, y))
                
            out = [ [0]*C for _ in range(R)] # on initialization output is 0
            
            for i in range(R):
                for j in range(C):
                    if (i,j) in bombs:
                        out[i][j]='*' #mark bom
                        continue
                    sums = 0
                    for ii in range(-1,2):
                        for jj in range(-1,2):
                            if (ii+i,jj+j) in bombs: #check if neighbour is bom
                                sums+=1
                    out[i][j]=str(sums)
                            
            for x in range(R):
                print("".join(out[x]))

main()
