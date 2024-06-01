import sys
input = sys.stdin.readline

for _ in range(int(input())):
    x, y, k = map(int, input().split())
    chest_loc = x
    if x < y:
        chest_loc = min(y, x + k)
    ans = max(chest_loc, y)
    if chest_loc < y:
        ans += y - chest_loc
    print(ans)