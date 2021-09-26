# Recommended imports for all problems
# Some problems may require more

import sys
import math
import string


def maze_parser(in_file):
    cases = []
    in_file = iter(in_file)
    case_count = int(next(in_file).rstrip())
    for case in range(case_count):
        dims = next(in_file).rstrip()
        w, h = dims.split(' ')
        w, h = int(w), int(h)
        maze = [list(next(in_file).rstrip()) for _ in range(h)]
        cases.append({'w': w, 'h': h, 'maze': maze})
    return cases


def get_map(w, h):
    map = []
    for w_cell in range(w):
        for h_cell in range(h):
            map.append((w_cell, h_cell))
    return map


def find_points(maze):
    start = None
    exits = []
    for r, row in enumerate(maze):
        for c, col in enumerate(row):
            if col == 'X':
                exits.append((c, r))
            if col == 'o':
                start = ((c, r))
    return start, exits


def create_path(came_from, current):
    path = [current]
    while current in came_from:
        current = came_from[current]
        path.append(current)
    return path


def get_neighbors(cell, maze):
    pot_n = ((cell[0], cell[1]-1),
             (cell[0]-1, cell[1]),
             (cell[0]+1, cell[1]),
             (cell[0], cell[1]+1))
    neighbors = []
    for n in pot_n:
        if 0 <= n[1] < len(maze):
            row = maze[n[1]]
            if 0 <= n[0] < len(row):
                unit = maze[n[1]][n[0]]
                if unit == ' ' or unit == 'X':
                    neighbors.append(n)
    return neighbors


def a_star(start, goal, map, maze):
    visited = []
    discovered = [start]
    came_from = {}
    g_score = {cell: math.inf for cell in map}
    g_score[start] = 0
    f_score = {cell: math.inf for cell in map}
    f_score[start] = math.fabs(start[0] - goal[0]) + math.fabs(start[1] - goal[1])

    while len(discovered) > 0:
        current = min(discovered, key=lambda cell: f_score[cell])
        if current == goal:
            return create_path(came_from, current), f_score[current]

        discovered.remove(current)
        visited.append(current)

        for neighbor in get_neighbors(current, maze):
            if neighbor in visited:
                continue

            next_g_score = g_score[current] + 1

            if neighbor not in discovered:
                discovered.append(neighbor)
            elif next_g_score >= g_score[neighbor]:
                continue

            came_from[neighbor] = current
            g_score[neighbor] = next_g_score
            f_score[neighbor] = g_score[neighbor] + math.fabs(neighbor[0] - goal[0]) + math.fabs(neighbor[1] - goal[1])

    return None, math.inf


def run(cases):
    outs = []
    for case in cases:
        w = case['w']
        h = case['h']
        maze = case['maze']
        map = get_map(w, h)

        path = None
        dist = math.inf
        start, exits = find_points(maze)
        for e in exits:
            new_path, new_dist = a_star(start, e, map, maze)
            if new_dist < dist:
                path = new_path
                dist = new_dist

        # render the path
        for p in path:
            if p != start and p not in exits:
                maze[p[1]][p[0]] = '.'
        outs.extend([''.join(row) for row in maze])
    return outs


if __name__ == "__main__":
    with open("Prob23.in.txt") as inputfile:    # Open the input file
        lines = [l for l in inputfile]
        cases = maze_parser(lines)
        outs = run(cases)
        for o in outs:
            print(o)
