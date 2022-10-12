# 17:03 ~ 17:15 ~ 17:30 X 점화식 못 찾음

case_count = int(input())
cases = [int(input()) for _ in range(case_count)]

dp = [1] * (max(cases)+1)

for i in range(2, max(cases)+1):
    dp[i] += dp[i-2]
for i in range(3, max(cases)+1):
    dp[i] += dp[i-3]

for case in cases:
    print(dp[case])

# import sys
# sys.setrecursionlimit(10**9)

# case_count = int(input())
# cases = [int(input()) for _ in range(case_count)]

# def dfs(n, prev):
#     if n > N:
#         return 0
#     elif n == N:
#         return 1

#     if 3 == prev:
#         return dfs(n+3, 3)
#     if 2 == prev:
#         return dfs(n+2, 2) + dfs(n+3, 3)
#     if 1 >= prev:
#         return dfs(n+1, 1) + dfs(n+2, 2) + dfs(n+3, 3)

# for case in cases:
#     N = case
#     print(dfs(0, 0))