# 16:30 ~ 

import math

H, W, N, M = map(int, input().split())
h, w = math.ceil(H/(N+1)), math.ceil(W/(M+1))
print(h*w)