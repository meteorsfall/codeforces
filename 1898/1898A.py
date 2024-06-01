import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, k = map(int, input().split())
    s = list(input().strip())
    b_count = 0
    for letter in s:
        if letter == 'B':
            b_count += 1
    if b_count == k:
        print(0)
        continue
    print(1)
    ans = []
    if b_count < k:
        a_count = 0
        for i, letter in enumerate(s):
            if letter == 'A':
                a_count += 1
            if b_count + a_count == k:
                ans = [i + 1, 'B']
    else:
        b_subcount = 0
        for i, letter in enumerate(s):
            if letter == 'B':
                b_subcount += 1
            if b_count - b_subcount == k:
                ans = [i + 1, 'A']
    print(*ans)