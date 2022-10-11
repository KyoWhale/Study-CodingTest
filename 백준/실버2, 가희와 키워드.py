# 17:59 ~ 18:15
import sys
input = sys.stdin.readline

N, M = map(int, input().rstrip().split())
keywords = dict()

for _ in range(N):
    keywords[input().rstrip()] = 1
for _ in range(M):
    used_keywords = input().rstrip().split(',')
    for key in used_keywords:
        if key in keywords:
            del keywords[key]
            N -= 1
    print(N)