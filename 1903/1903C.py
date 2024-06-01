import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    arr = [int(i) for i in input().split()]
    arr.reverse()
    running_sum = 0
    c_sum = 0
    for i, num in enumerate(arr):
        running_sum += num
        if running_sum > 0:
            c_sum += running_sum
    if running_sum < 0:
        c_sum += running_sum
    print(c_sum)