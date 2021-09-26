# Recommended imports for all problems
# Some problems may require more
import sys
import math
import string

def markAnswer(puzzle, options, answer, row, col):
        puzzle[row][col] = answer
        options[row][col] = set()
        for idx in range(9):
                options[idx][col].discard(answer)
                options[row][idx].discard(answer)
                subGridRow = (math.floor(row / 3) * 3) + math.floor(idx / 3)
                subGridCol = (math.floor(col / 3) * 3) + (idx % 3)
                options[subGridRow][subGridCol].discard(answer)

def solve(puzzle, options, numbersLeft):
        answerMarked = True
        minOptions = 9
        splitRow = 9
        splitCol = 9
        while answerMarked and numbersLeft > 0:
                answerMarked = False
                minOptions = 9
                splitRow = 9
                splitCol = 9
                for row in range(9):
                        for col in range(9):
                                if len(options[row][col]) == 0 and puzzle[row][col] == '_':
                                        return False
                                elif len(options[row][col]) == 1:
                                        answer = options[row][col].pop()
                                        numbersLeft -= 1
                                        markAnswer(puzzle, options, answer, row, col)
                                        answerMarked = True
                                        break
                                elif len(options[row][col]) > 0 and len(options[row][col]) < minOptions:
                                        minOptions = len(options[row][col])
                                        splitRow = row
                                        splitCol = col
                        if answerMarked:
                                break
        if numbersLeft > 0:
                numbersLeft -= 1
                for i in range(minOptions):
                        puzzleCopy = [None] * 9
                        optionsCopy = [None] * 9
                        for row in range(9):
                                puzzleCopy[row] = [None] * 9
                                optionsCopy[row] = [None] * 9
                                for col in range(9):
                                        puzzleCopy[row][col] = puzzle[row][col]
                                        optionsCopy[row][col] = set(options[row][col])
                        option = options[splitRow][splitCol].pop()
                        markAnswer(puzzleCopy, optionsCopy, option, splitRow, splitCol)
                        result = solve(puzzleCopy, optionsCopy, numbersLeft)
                        if result:
                                for row in range(9):
                                        puzzle[row] = [None] * 9
                                        options[row] = [None] * 9
                                        for col in range(9):
                                                puzzle[row][col] = puzzleCopy[row][col]
                                                options[row][col] = set(optionsCopy[row][col])
                                return True
                return False
        else:
                return True
        

# Always start with reading in the number
# of test cases from standard input. The
# rstrip() method removes the lingering newline
cases = int(sys.stdin.readline().rstrip())
# Loop for each test case. This is the last line
# common to all problems; the content of this
# loop will change based on the problem solved.
for caseNum in range(cases):
        puzzle = [None] * 9
        # Read original puzzle
        for i in range(9):
                puzzle[i] = list(sys.stdin.readline().rstrip())
        # Set up process of elimination
        options = [None] * 9;
        for row in range(9):
                options[row] = [None] * 9;
                for col in range(9):
                        options[row][col] = set('123456789')
        # Start eliminating options
        numbersLeft = 81
        for row in range(9):
                for col in range(9):
                        answer = puzzle[row][col]
                        if answer != '_':
                                markAnswer(puzzle, options, answer, row, col)
                                numbersLeft -= 1
        # Start solving
        result = solve(puzzle, options, numbersLeft)
        if not result:
                print("error")
        # Print final solution
        for row in range(9):
                for col in range(9):
                        print(puzzle[row][col], end="")
                print()
