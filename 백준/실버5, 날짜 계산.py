# 16:30 ~ 16:43

E, S, M = map(int, input().split())
e,s,m = 1,1,1
year = 1
while not (e == E and s == S and m == M):
    e = max((e+1) % 16, 1)
    s = max((s+1) % 29, 1)
    m = max((m+1) % 20, 1)
    year += 1
print(year)