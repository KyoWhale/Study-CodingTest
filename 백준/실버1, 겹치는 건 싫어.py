# 16:48 ~ 16:25 dic, queue 썼는데 틀림
# ~ 16:32 투 포인터 해답 봄

N, K = map(int, input().split())
nums = list(map(int, input().split()))
counter = [0] * (max(nums)+1)
left, right = 0, 0
answer = 0

while right < N:
    if counter[nums[right]] < K:
        counter[nums[right]] += 1
        right += 1
    else:
        counter[nums[left]] -= 1
        left += 1
    answer = max(answer, right - left)

print(answer)

"""
9 2
1 1 2 3 4 5 1 7 8

9 3
1 1 1 3 4 5 1 7 8
"""