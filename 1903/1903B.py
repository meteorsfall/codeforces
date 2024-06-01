import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    m = []
    for i in range(n):
        m_i = [int(j) for j in input().split()]
        m.append(m_i)
    unlock = []
    for i in range(n):
        bits = m[i][(i + 1) % n]
        for j in range(n):
            if i != j:
                bits &= m[i][j]
        unlock.append(bits)
    valid = True
    for i in range(n):
        for j in range(n):
            if i != j:
                if m[i][j] != unlock[i] | unlock[j]:
                    valid = False
    if valid:
        print("YES")
        print(*unlock)
    else:
        print("NO")