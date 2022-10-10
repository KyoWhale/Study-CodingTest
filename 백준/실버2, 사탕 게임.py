# 15:48 ~ 16:29 X

def getCount(table, N):
    max_count = 1

    for i in range(N):
        count = 1
        for j in range(N-1):
            if table[i][j] == table[i][j+1]:
                count += 1
                max_count = max(max_count, count)
            else:
                count = 1

        count = 1
        for j in range(N-1):
            if table[j][i] == table[j+1][i]:
                count += 1
                max_count = max(max_count, count)
            else:
                count = 1
                
    return max_count

N = int(input())
table = [list(input()) for _ in range(N)]
answer = 0
for i in range(N):
    for j in range(N-1):
        table[i][j], table[i][j+1] = table[i][j+1], table[i][j]
        answer = max(answer, getCount(table, N))
        table[i][j], table[i][j+1] = table[i][j+1], table[i][j]

        table[j][i], table[j+1][i] = table[j+1][i], table[j][i]
        answer = max(answer, getCount(table, N))
        table[j][i], table[j+1][i] = table[j+1][i], table[j][i]
print(answer)