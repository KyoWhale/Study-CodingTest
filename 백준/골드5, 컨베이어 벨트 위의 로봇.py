# 19:21 ~ 19:50 X 구현인 것 같아서 코드는 쭉 써봄
# ~ 19:56 디큐의 로테이트가 있다는 것을 처음 암

import sys
from collections import deque
input = sys.stdin.readline

N, K = map(int, input().split())
belt = deque(list(map(int, input().split())))
robot = deque([0]*N)
answer = 0
count = 0

while count < K:
    belt.rotate(1)
    robot.rotate(1)
    robot[-1] = 0

    if sum(robot):
        for i in range(N-2,-1,-1):
            if robot[i] == 1 and robot[i+1] == 0 and belt[i+1] > 0:
                robot[i+1] = 1
                robot[i] = 0
                belt[i+1] -= 1
                if belt[i+1] == 0:
                    count += 1
        robot[-1] = 0

    if robot[0] == 0 and belt[0] > 0:
        robot[0] = 1
        belt[0] -= 1
        if belt[0] == 0:
            count +=1
    answer += 1

print(answer)


# N, K = map(int, input().split())
# durability = list(map(int, input().split()))
# MAX = 2 * N - 1

# up, down = 0, N
# answer = 0
# count = 0
# robots = []

# while count < K:
#     answer += 1

#     up -= 1
#     if up == -1:
#         up = MAX
#     down = (up + N - 1) % (MAX+1)

#     remove = []
#     for i in range(len(robots)):
#         next = (robots[i]+1) % (MAX+1)
#         if next == down:
#             remove.append(i)
#             continue

#         if durability[next] == 0:
#             continue
#         durability[next] -= 1
#         robots[i] = next

#     if durability[up] > 0:
#         robots.append(up)
#         durability[up] -= 1
#         if durability[up] == 0:
#             count += 1

# print(answer)