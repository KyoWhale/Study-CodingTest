# 14:58 ~ 

a, b, c = map(int, input().split())
result = []
while not (a == 0 and b == 0 and c == 0):
    if a == b and b == c:
        result.append("Equilateral")
    elif max([a,b,c]) * 2 >= sum([a,b,c]):
        result.append("Invalid")
    elif a == b or b == c or a == c:
        result.append("Isosceles")
    else:
        result.append("Scalene")

    a, b, c = map(int, input().split())

for line in result:
    print(line)