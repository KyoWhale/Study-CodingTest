# 16:00 ~ 16:26

from copy import deepcopy

N, d, k, c = map(int, input().split())
sushis = [int(input()) for i in range(N)]
sushis += deepcopy(sushis[:k])

current = deepcopy(sushis[:k])
dic = {}
kind = 0
for sushi in current:
    if sushi in dic:
        dic[sushi] += 1
    else:
        dic[sushi] = 1
        kind += 1

if c in dic:
    answer = kind
else:
    answer = kind + 1
    dic[c] = 0

for i in range(N):
    poped = current.pop(0)
    pushed = sushis[i+k]
    current.append(pushed)

    dic[poped] -= 1
    if dic[poped] == 0:
        kind -= 1
    
    if pushed in dic:
        if dic[pushed] == 0:
            kind += 1
        dic[pushed] += 1
    else:
        dic[pushed] = 1
        kind += 1

    if dic[c] > 0:
        answer = max(answer, kind)
    else:
        answer = max(answer, kind+1)

print(answer)