# 16:35 ~ 17:17 X
# ~ 19:00 디큐를 이용하지 않았고 튜플에 x, y의 순서가 바뀌어서 넣어 오류가 남

from collections import deque
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
graph = [list(map(int,input().rstrip())) for _ in range(N)]
visit = [[[0,0] for _ in range(M)] for _ in range(N)]
visit[0][0][0] = 1

def bfs():
    q = deque([(0,0,0)])
    while q:
        wall, x, y = q.popleft()

        if x == M-1 and y == N-1:
            return visit[y][x][wall]

        for dx, dy in zip([1,0,-1,0],[0,1,0,-1]):
            nx, ny = x + dx, y + dy

            if 0 <= nx < M and 0 <= ny < N and visit[ny][nx][wall] == 0:
                if graph[ny][nx] == 0:
                    visit[ny][nx][wall] = visit[y][x][wall] + 1
                    q.append((wall,nx,ny))
                
                if wall == 0:
                    visit[ny][nx][1] = visit[y][x][wall] + 1
                    q.append((1,nx,ny))
    return -1

print(bfs())