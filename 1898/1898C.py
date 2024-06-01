import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, m, k = map(int, input().split())
    rem = k - (n - 1) - (m - 1)
    if rem < 0:
        print("NO")
        continue
    if rem % 2 != 0:
        print("NO")
        continue
    horiz = [['R' for i in range(m - 1)] for j in range(n)]
    vert = [['R' for i in range(m)] for j in range(n-1)]
    for i in range(m-1):
        if i % 2 == 0:
            horiz[0][i] = 'B'
    for i in range(n-1):
        if i % 2 != 0:
            vert[i][m-1] = horiz[0][m-2]
        else:
            vert[i][m-1] = horiz[0][m-3]
    horiz[1][0] = 'B'
    last = vert[n-2][m-1]
    flip = 'R' if last == 'B' else 'B'
    vert[n-2][m-2] = flip
    horiz[n-1][m-2] = last
    horiz[n-2][m-2] = last
    print("YES")
    for row in horiz:
        print(*row)
    for row in vert:
        print(*row)