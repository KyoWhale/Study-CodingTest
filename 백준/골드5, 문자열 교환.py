# 15:35 ~ X

s = input()
a = s.count('a')

answer = len(s) - a
for i in range(a - 1, len(s)):
    answer = min(answer, s[i - a + 1:i + 1].count('b'))

for i in range(0, a - 1):
    answer = min(answer, (s[i - a + 1:] + s[:i + 1]).count('b'))

print(answer)