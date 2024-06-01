import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    arr = [int(i) for i in input().split()]
    arr.sort()
    coords = []
    for i in range(n):
        coords.append((arr[i], arr[n + i]))
    print(coords[-1][0] - coords[0][0] + coords[-1][1] - coords[0][1])
    for row in coords:
        print(*row)