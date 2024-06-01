import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    n = int(input())
    arr = [int(i) for i in input().split()]
    arr.reverse()
    goal = arr[0]
    ops = 0
    for num in arr:
        if num > goal:
            splits = math.ceil(num/goal)
            ops += splits - 1
            goal = num//splits
        elif num < goal:
            goal = num
    print(ops)