# 15:46 ~ 15:51

import heapq
import sys
input = sys.stdin.readline

q = []
N = int(input())
nums = [int(input().rstrip()) for _ in range(N)]

for num in nums:
    if num == 0:
        if q:
            print(heapq.heappop(q))
        else:
            print(0)
    else:
        heapq.heappush(q, num)