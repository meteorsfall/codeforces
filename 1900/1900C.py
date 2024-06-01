import sys
from typing import List
input = sys.stdin.readline

def traverse(v: int, tree, costs: List[int], s, running_cost: int): 
    costs[v] = running_cost
    l = tree[v][0]
    if l != -1:
        l_cost = running_cost
        if s[v] != 'L':
            l_cost += 1
        traverse(l, tree, costs, s, l_cost)
    r = tree[v][1]
    if r != -1:
        r_cost = running_cost
        if s[v] != 'R':
            r_cost += 1
        traverse(r, tree, costs, s, r_cost) 

for _ in range(int(input())):
    n = int(input())
    s = list(input().strip())
    tree = []
    parents = [-1]*n
    for i in range(n):
        l, r = map(int, input().split())
        tree.append((l - 1, r - 1))
        parents[l-1] = i
        parents[r-1] = i
    costs = [n]*n
    #print(tree)
    q = [(0, 0)]
    while len(q) > 0:
        v, running_cost = q.pop()
        costs[v] = running_cost
        l = tree[v][0]
        if l != -1:
            l_cost = running_cost
            if s[v] != 'L':
                l_cost += 1
            q.append((l, l_cost))
        r = tree[v][1]
        if r != -1:
            r_cost = running_cost
            if s[v] != 'R': 
                r_cost += 1
            q.append((r, r_cost))
        
    min_cost = n
    for i in range(n):
        if tree[i][0] == -1 and tree[i][1] == -1:
            min_cost = min(min_cost, costs[i])
    print(min_cost)