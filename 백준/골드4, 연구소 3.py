# 13:48 ~ 14:55 X 82%에서 틀림
# 비활성 바이러스가 있는 곳을 갈 때는 time을 업데이트 해주지 않는 것이 포인트

from collections import deque
from itertools import combinations
import sys

input = sys.stdin.readline
N, M = map(int, input().split())
table = [list(map(int, input().split())) for _ in range(N)]
virus = []
wall_count = 0

def bfs(points):
    q = deque()
    visit = [[-1]* N for _ in range(N)]
    max_time = 0

    for x, y in points:
        q.append((0,x,y))
        visit[y][x] = 0

    while q:
        time, x, y = q.popleft()

        for dx, dy in zip([1,0,-1,0],[0,1,0,-1]):
            nx, ny = x+dx, y+dy

            if 0 <= nx < N and 0 <= ny < N:
                if table[ny][nx] == 0 and visit[ny][nx] == -1:
                    q.append((time+1, nx, ny))
                    visit[ny][nx] = time + 1
                    max_time = max(max_time, time+1)
                elif table[ny][nx] == 2 and visit[ny][nx] == -1:
                    q.append((time+1, nx, ny))
                    visit[ny][nx] = time + 1

    if list(sum(visit, [])).count(-1) != wall_count:
        return 10e9
    return max_time

for i in range(N):
    for j in range(N):
        if table[i][j] == 1:
            wall_count += 1
        elif table[i][j] == 2:
            virus.append((j,i))

answer = 10e9
for points in combinations(virus, M):
    answer = min(answer, bfs(points))

if answer == 10e9:
    print(-1)
else:
    print(answer)

# from copy import deepcopy
# from itertools import combinations

# N, M = map(int, input().split())
# table = [list(map(int, input().split())) for _ in range(N)]
# virus_points = []
# should_visit = []

# for i in range(N):
#     for j in range(N):
#         if table[i][j] == 2:
#             table[i][j] = -2
#             virus_points.append((j, i))
#         elif table[i][j] == 1:
#             table[i][j] == -1
#         else:
#             should_visit.append((i,j))

# def bfs(points, board):
#     for x, y in virus_points:
#         board[y][x] = 1

#     visit = []
#     q = list(points)
#     while q:
#         x, y = q.pop(0)

#         for dx, dy in zip([1,0,-1,0],[0,1,0,-1]):
#             nx, ny = x+dx, y+dy
#             if 0 <= nx < N and 0 <= ny < N:
#                 if board[ny][nx] == -1:
#                     continue
#                 elif board[ny][nx] == 0:
#                     board[ny][nx] = board[y][x]+1
#                     visit.append((nx,ny))
#                     q.append((nx,ny))
#                 elif len(visit) < len(should_visit) and board[ny][nx] == -2:
#                     board[ny][nx] = board[y][x]+1
#                     q.append((nx,ny))

#     max_time = 0
#     for i in range(N):
#         for j in range(N):
#             if board[i][j] == 0:
#                 return 10e9
#             max_time = max(max_time, board[i][j])

#     return max_time-1

# answer = 10e9
# for points in combinations(virus_points, M):
#     dup_table = deepcopy(table)
#     answer = min(answer, bfs(points, dup_table))

# if answer == 10e9:
#     print(-1)
# else:
#     print(answer)