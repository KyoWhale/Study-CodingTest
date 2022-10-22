# 14:39 ~ 14:57

import sys
input = sys.stdin.readline

N = int(input())
request_list = list(map(int, input().split()))
M = int(input())

left, right = 0, max(request_list)
while left <= right:
    mid = (left+right)//2

    total = 0
    for request in request_list:
        if mid < request:
            total += mid
        else:
            total += request

    if total > M:
        right = mid - 1
    else:
        left = mid + 1

print(right)