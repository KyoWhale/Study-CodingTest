# 15:44 ~ 15:47

from itertools import combinations

heights = [int(input()) for _ in range(9)]
for combination in combinations(heights, 7):
    if sum(combination) == 100:
        for height in sorted(combination):
            print(height)
        break