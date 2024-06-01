import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    d = [[] for _ in range(n + 1)]
    for _ in range(n-1):
        a,b = map(int, input().split())
        d[a].append(b)
        d[b].append(a)
    leaves = [1 if len(i) == 1 else 0 for i in d]
    num_leaves = sum(leaves)
    ans = (num_leaves+1)//2
    print(ans)