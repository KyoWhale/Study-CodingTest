# 17:11 ~ 17:44 X

width, height, tram_len, star_len = map(int, input().split())
star_points = []
for _ in range(star_len):
    x, y = map(int, input().split())
    star_points.append((x,y))
star_points.sort()

answer = 0
for ax, ay in star_points:
    for bx, by in star_points:
        count = 0
        for x, y in star_points:
            if ax <= x <= ax+tram_len and by <= y <= by+tram_len:
                count += 1
            answer = max(answer, count)

print(star_len-answer)