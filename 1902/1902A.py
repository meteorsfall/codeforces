import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s = list(input().strip())
    good = False
    for bit in s:
        if bit == '0':
            good = True
    if good:
        print("YES")
    else:
        print("NO")