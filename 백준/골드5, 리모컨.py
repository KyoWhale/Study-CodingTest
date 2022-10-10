# 16:46 ~ 17:40 X 

# N, M = input(), int(input())
# broken = list(map(int, input().split()))
# not_broken = [i for i in [0,1,2,3,4,5,6,7,8,9] if i not in broken]
# channel = ''

# if N == '100':
#     print(0)
#     exit()
# elif M == 0:
#     print(len(N))
#     exit()
# elif M == 10:
#     print(abs(int(N)-100))
#     exit()

# small, big = '', ''
# for i in range(len(N)):
#     if int(N[i]) in not_broken:
#         small += N[i]
#     else:
#         small += str(max(not_broken)) * (len(N)-i)
#         break

# for i in range(len(N)):
#     if int(N[i]) in not_broken:
#         big += N[i]
#     else:
#         big += str(min(not_broken)) * (len(N)-i)
#         break

# answer = min(abs(int(N)-int(small)), abs(int(N)-int(big))) + len(N)
# print(answer)

N, M = int(input()), int(input())
if M:
    broken = list(map(int, input().split()))
else:
    broken = []

answer = abs(100 - N)

for num in range(10000001):
    num = str(num)

    for i in range(len(num)):
        if int(num[i]) in broken:
            break
    else:
        answer = min(answer, abs(int(num) - N) + len(num))

print(answer)