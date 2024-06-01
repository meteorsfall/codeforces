import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s = list(input().strip())
    running_free = 0
    regen = False
    total_spots = 0
    for cell in s:
        if cell == '.':
            total_spots += 1
            running_free += 1
            if running_free >= 3:
                regen = True
        else:
            running_free = 0
    if regen:
        print(2)
    else:
        print(total_spots)