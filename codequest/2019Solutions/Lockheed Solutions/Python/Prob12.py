import sys 
import decimal

def main():
    cases = int(sys.stdin.readline().rstrip()) 
    
    for caseNum in range(cases): 
        N,r,d = tuple(map(int,(sys.stdin.readline().rstrip().split())))
        p = decimal.Decimal(1)
        for x in range(r):
            p = p * decimal.Decimal(N-1)/decimal.Decimal(N)
            N = N - 1 - d
                 
        p1 = format(round(100*p/decimal.Decimal(N),2),"0.02f")   
        print(p1+'%')

main()

