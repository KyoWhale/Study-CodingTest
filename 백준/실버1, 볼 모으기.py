# 16:30 ~ 17:00

N = int(input())
balls = input()

back_color = 1
for ball in balls[:-1]:
    if ball == balls[-1]:
        back_color += 1
other_color = N-back_color

back = 1
for i in range(N-2,-1,-1):
    if balls[i] == balls[-1]:
        back += 1
    else:
        break

if balls[0] == balls[-1]:
    front_color = back_color
else:
    front_color = N - back_color

front = 1
for i in range(1,N):
    if balls[i] == balls[0]:
        front += 1
    else:
        break

answer = min([back_color, other_color, back_color-back, front_color-front])

if back_color == N:
    print(0)
else:
    print(answer)