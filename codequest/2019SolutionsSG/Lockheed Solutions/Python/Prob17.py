# Recommended imports for all problems
# Some problems may require more

import sys
import math
import string


def conway_parser(in_file):
    cases = []
    in_file = iter(in_file)
    case_count = int(next(in_file).rstrip())
    for _ in range(case_count):
        t = int(next(in_file).rstrip())
        game = []
        for __ in range(10):
            row = list(next(in_file).rstrip())
            game.append(row)
        cases.append((t, game))
    return cases


def convolution(state, row, col):
    count = 0
    for r in range(row-1, row+2):
        for c in range(col-1, col+2):
            if r == row and c == col:
                continue
            if state[r][c] == '1':
                count += 1
    return count


def run(cases):
    out = []
    for case in cases:
        state = case[1]

        # pad the game state with dead cells
        state = [['0'] + row[:] + ['0'] for row in state]
        state.insert(0, ['0'] * 12)
        state.append(['0'] * 12)

        for _ in range(case[0]):
            new_state = [list(row) for row in state]  # do a deep copy so we can modify the new state w/o changing orig
            for row in range(1, 11):
                for col in range(1, 11):
                    count = convolution(state, row, col)
                    if state[row][col] == '1':
                        if count <= 1 or count >= 4:
                            new_state[row][col] = '0'
                    elif count == 3:
                        new_state[row][col] = '1'
            state = new_state

        out.extend(["".join(row[1:-1]) for row in state[1:-1]])  # strip the padding when printing

    return out


if __name__ == "__main__":
    with open("Prob17.in.txt") as inputfile:    # Open the input file
        lines = [l for l in inputfile]
        cases = conway_parser(lines)
        outs = run(cases)
        for o in outs:
            print(o)
