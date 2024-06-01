import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s = list(input().strip())
    subseq = []
    for i, letter in enumerate(s):
        while subseq and subseq[-1][0] < letter:
            subseq.pop()
        subseq.append((letter, i))
    final = s.copy()
    for i, (letter, index) in enumerate(subseq):
        final[index] = subseq[-1-i][0]
    prefix = 0
    for letter, index in subseq:
        if letter == subseq[0][0]:
            prefix += 1
    if sorted(s) == final:
        print(len(subseq) - (prefix))
    else:
        print(-1)