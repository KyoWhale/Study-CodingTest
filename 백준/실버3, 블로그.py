# 17:57 ~ 18:09 채점 결과 기다리는 중
# 13:20 ~ 13:31

total_day, period = map(int, input().split())
days = list(map(int, input().split()))

if max(days) == 0:
    print("SAD")
else:
    start = 0
    cur_visitor = sum(days[:period])
    max_visitor = cur_visitor
    max_count = 1

    while start+period < total_day:
        cur_visitor = cur_visitor + days[start+period] - days[start]

        if cur_visitor > max_visitor:
            max_count = 1
            max_visitor = cur_visitor
        elif cur_visitor == max_visitor:
            max_count += 1

        start += 1

    print(max_visitor)
    print(max_count)