import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, k = map(int, input().split())
    arr = [int(i) for i in input().split()]
    if arr == sorted(arr):
        print("YES")
        continue
    if (k > 1):
        print("YES")
    else:
        print("NO")