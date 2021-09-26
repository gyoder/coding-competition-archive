import sys
import math
import string

allCases = int(sys.stdin.readline().rstrip())
caseTime = 0
caseNum = 1
while caseTime < allCases:
    cases = sys.stdin.readline().rstrip().split(" ")
    board = []
    for i in range(0, int(cases[0])):
        board.append([])
        for j in range(0, int(cases[1])):
            board[-1].append(0)
        caseNum += 1
    for i in range(0, int(cases[2])):
        bombs = [int(j) for j in sys.stdin.readline().rstrip().split(" ")]
        board[bombs[0]][bombs[1]] = "*"
    for i in range(0, len(board)):
        for j in range(0, len(board[i])):
            drs = [[1, 0], [1, 1], [0, 1], [-1, 1], [-1, 0], [-1, -1], [0, -1], [1, -1]]
            if board[i][j] != "*":
                continue
            for l in drs:
                if i + l[0] >= 0 and i + l[0] < len(board) and j + l[1] >= 0 and j + l[1] < len(board[0]):
                    if board[i + l[0]][j + l[1]] != "*":
                        board[i + l[0]][j + l[1]] += 1 
                                                                                                
    caseNum += 1
    caseTime += 1
    print("\n".join(["".join([str(j) for j in i]) for i in board]))
                
    
