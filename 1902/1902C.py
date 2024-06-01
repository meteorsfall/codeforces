import sys
import math
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    arr = [int(i) for i in input().split()]
    arr.sort()
    if n == 1:
        print(1)
        continue
    x = arr[-1] - arr[-2]
    for num in arr:
        x = math.gcd(x, arr[-1] - num)
    ops = 0
    for num in arr:
        ops += (arr[-1] - num)/x
    missing_num = None
    for i, num in enumerate(arr):
        if i == 0:
            continue
        if num != arr[i-1] + x:
            missing_num = num - x
    if missing_num == None:
        ops += n
    else:
        ops += (arr[-1] - missing_num)/x
    #print(arr)
    print(int(ops))