# 14:27 ~ 14:57 X 55%에서 틀림
# ~ 15:41 다엑스트라 해답 보고 품

import heapq

N, D = map(int, input().split())
roads = []
answer = 10e9
for _ in range(N):
    start, end, distance = map(int, input().split())
    if end <= D:
        roads.append((start,end,distance))

distance = [i for i in range(D+1)]
q = []
heapq.heappush(q, (0, 0))
while q:
    cur_cost, cur = heapq.heappop(q)
    if cur > D:
        continue

    if distance[D] > cur_cost + D-cur:
        distance[D] = cur_cost + D-cur

    for start, end, cost in roads:
        if cur > start: continue
        low_cost = cur_cost + cost + start-cur
        if distance[end] > low_cost:
            distance[end] = low_cost
            heapq.heappush(q, (low_cost,end))

print(distance[D])

# N, D = map(int, input().split())
# roads = []
# answer = 10e9
# for _ in range(N):
#     start, end, distance = map(int, input().split())
#     if end <= D:
#         roads.append((start,end,distance))

# def dfs(current, total_distance):
#     global answer

#     if current > D:
#         return

#     if current == D:
#         answer = min(answer, total_distance)
#         return

#     for start, end, distance in roads:
#         if current <= start:
#             dfs(end, (start-current) + distance + total_distance)
#     answer = min(answer, total_distance + D-current)

# for start, end, distance in roads:
#     dfs(end, start + distance)

# print(answer)