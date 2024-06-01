import sys
input = sys.stdin.readline

for _ in range(int(input())):
    a, b, c = [int(i) for i in input().strip().split()]
    ans = [0]*3
    if (b - c) % 2 == 0 and a + min(b,c) >= 1:
        ans[0] = 1
    if (a - c) % 2 == 0 and b + min(a,c) >= 1:
        ans[1] = 1
    if (a - b) % 2 == 0 and c + min(a,b) >= 1:
        ans[2] = 1
    print(*ans)