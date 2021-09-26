import sys 

def main():
    cases = int(sys.stdin.readline().rstrip()) 
    
    for caseNum in range(cases): 
        line = sys.stdin.readline().rstrip()
        R,C,B = map(int,line.split())
        bombs = set()
        for _ in range(B):
            line=sys.stdin.readline().rstrip()
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
