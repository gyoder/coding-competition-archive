import sys 
import collections

Path = collections.namedtuple("Path","from_,to")

def path_order(paths):
    result = []
    while len(paths)>1: #fnish when only one route exists
        #get city that is not in any path as starting position
        last_city = list(set([ x.to for x in paths])-set([ x.from_ for x in paths]))[0]        
        result.append(last_city)
        # remove path with last_city
        paths = [x for x in paths if x.to != last_city]
    x=paths[0]
    result.append(x.to)
    result.append(x.from_)
    return result

def main():
    cases = int(sys.stdin.readline().rstrip()) 
    
    for caseNum in range(cases):         
        path_number = int(sys.stdin.readline().rstrip())
        paths=[]
        for x in range(path_number):
            from_, to = tuple(sys.stdin.readline().rstrip().split())
            paths.append(Path(from_, to))            
        for path in path_order(paths):
            print(path) 

main()
