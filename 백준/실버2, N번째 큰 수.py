# 17:28 ~ 17:51

import heapq
import sys

input = sys.stdin.readline
N = int(input())

q = []
for i in range(N):
    li = list(map(int, input().split()))
    for num in li:
        if len(q) < N:
            heapq.heappush(q, num)
        else:
            if q[0] < num:
                heapq.heappop(q)
                heapq.heappush(q, num)

print(q[0])