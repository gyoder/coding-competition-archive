for t in range(int(input())):
    X = int(input())
    a = [list(map(int, list(input()))) for _ in range(10)]
    m = [[0] * 12 for _ in range(12)]
    m1 = [[0] * 12 for _ in range(12)]
    for i in range(1, 11):
        for j in range(1, 11):
            m[i][j] = a[i-1][j-1]
    for _ in range(X):
        for i in range(1, 11):
            for j in range(1, 11):
                n = 0
                for i1 in range(-1, 2):
                    for j1 in range(-1, 2):
                        if i1 == j1 == 0: continue
                        n += m[i+i1][j+j1]
                if m[i][j] == 1: # alive
                    if n <= 1 or n >= 4:
                        m1[i][j] = 0
                    else:
                        m1[i][j] = 1
                else:
                    if n == 3:
                        m1[i][j] = 1
        for i in range(12):
            for j in range(12):
                m[i][j] = m1[i][j]
        m1 = [[0] * 12 for _ in range(12)]
        for i in range(12):
            m[0][i] = 0
            m[11][i] = 0
            m[i][0] = 0
            m[i][11] = 0
    for i in range(1, 11):
        print(''.join(map(str, m[i][1:11])))
