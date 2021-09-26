import sys 

def  can_be_seen(xs,ys,xc,yc,xw1,yw1,xw2,yw2):
    def get_ABC(x1,y1,x2,y2): #line equation Ax+By+C=0
        A = y2-y1
        B = -(x2-x1)
        C = -(A*x1+B*y1)
        return (A,B,C)    
    
    ret = False # assume that spy cannot be seen
        
    A,B,C = get_ABC(xw1,yw1,xw2,yw2)    # wall line
    side_w = (A*xs+B*ys+C) * (A*xc+B*yc+C) #that same side or oppposite
    
    if side_w>0:
        ret = True
    
    A,B,C = get_ABC(xc,yc,xw1,yw1)  #wall corner  - camera line 
    side_w = (A*xs+B*ys+C) * (A*xw2+B*yw2+C) 
      
    if side_w<0:
        ret = True
    
    A,B,C = get_ABC(xc,yc,xw2,yw2) #wall corner - camera line 
    side_w = (A*xs+B*ys+C) * (A*xw1+B*yw1+C)
         
    if side_w<0:
        ret = True
    
    return ret

def main():
    cases = int(sys.stdin.readline().rstrip()) 
    
    for caseNum in range(cases): 
        line=sys.stdin.readline().rstrip()
        (xs,ys,xc,yc,w) = list(map(int,line.split()))
        
        result="YES"
        
        for _ in range(w):
            line=sys.stdin.readline().rstrip()
            (xw1,yw1,xw2,yw2) = list(map(int,line.split()))
            
            if not can_be_seen(xs,ys,xc,yc,xw1,yw1,xw2,yw2):
                result = "NO"
                
        print(result)
main()

    























    
    
    