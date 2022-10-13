# 15:54 ~ 16:15 X dp로 했는데 안 풀림
# 16:32 ~ 16:46 deque, bfs로

from collections import deque

MAX = 100001
N, K = map(int, input().split())
visit = [False] * MAX
distance = [10e9] * MAX
visit[N] = True
distance[N] = 0

q = deque()
q.append((0,N))
while q:
    second, coord = q.popleft()
    if 2*coord < MAX and visit[2*coord] == False:
        distance[2*coord] = second
        visit[2*coord] = True
        q.appendleft((second, 2*coord))
    if 0 <= coord-1 and visit[coord-1] == False:
        distance[coord-1] = second+1
        visit[coord-1] = True
        q.append((second+1, coord-1))
    if coord+1 < MAX and visit[coord+1] == False:
        distance[coord+1] = second+1
        visit[coord+1] = True
        q.append((second+1, coord+1))
print(distance[K])

# N, K = map(int, input().split())
# dp = [10e9] * 10000001

# if K <= N:
#     print(N-K)
#     exit()

# for i in range(N, K+1, N):
#     dp[i] = 0
#     for index, j in enumerate(range(i-1,i-N//2-1,-1)):
#         dp[j] = min(dp[j], index+1)
#     for index, j in enumerate(range(i+1,i+N//2+1)):
#         dp[j] = min(dp[j], index+1)
# print(dp[K])
