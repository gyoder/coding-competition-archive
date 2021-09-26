# Recommended imports for all problems
# Some problems may require more

import sys
import math
import string


def knn_parser(in_file):
    in_file = iter(in_file)
    test_count = int(next(in_file).rstrip())
    cases = []
    for i in range(test_count):
        counts = next(in_file).rstrip()
        x_len, y_len = counts.split(' ')
        x_len, y_len = int(x_len), int(y_len)

        # read the known dataset
        x = []
        for _ in range(x_len):
            row = next(in_file).rstrip().split(' ')
            row[1:] = [float(f) for f in row[1:]]
            x.append(row)

        # read the unknown test cases
        y = []
        for _ in range(y_len):
            row = next(in_file).rstrip().split(' ')
            row = [float(f) for f in row]
            y.append(row)

        cases.append((x, y))
    return cases


def distance(x, y):
    dims = [(n1-n2)**2 for n1, n2 in zip(x, y)]
    d = 0
    for dim in dims:
        d += dim
    return math.sqrt(d)


def vote(k, distances):
    votes = {}
    for i in range(k):
        if distances[i][1] not in votes:
            votes[distances[i][1]] = 0
        votes[distances[i][1]] += 1

    max = 0
    ties = 0
    highest_class = None

    for c in votes.keys():
        if votes[c] > max:
            max = votes[c]
            ties = 0
            highest_class = c
        elif votes[c] == max:
            ties += 1
            highest_class = None
    return highest_class

def run(cases):
    out = []
    for case in cases:
        for y in case[1]:
            distances = [(distance(x[1:], y), x[0]) for x in case[0]]
            distances.sort(key=lambda x: x[0])

            k = 5
            voted_class = vote(k, distances)
            while voted_class is None:
                k += 1
                voted_class = vote(k, distances)

            out.append(voted_class)
    return out


if __name__ == "__main__":
    with open("Prob20.in.txt") as inputfile:    # Open the input file
        lines = [l for l in inputfile]
        cases = knn_parser(lines)
        outs = run(cases)
        for o in outs:
            print(o)
