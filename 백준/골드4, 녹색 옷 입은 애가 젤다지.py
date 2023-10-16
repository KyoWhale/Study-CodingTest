# 17:35 ~ 17:53

dx, dy = [1,0,-1,0], [0,1,0,-1]

def bfs(cost_board, size):
    q = [(0, 0)]
    board = [[10e9] * size for _ in range(size)]
    board[0][0] = cost_board[0][0]

    while q:
        x, y = q.pop(0)
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if 0 <= nx < size and 0 <= ny < size:
                if board[ny][nx] > board[y][x] + cost_board[ny][nx]:
                    board[ny][nx] = board[y][x] + cost_board[ny][nx]
                    q.append((nx,ny))

    return board[size-1][size-1]

answers = []
size = int(input())
while size != 0:
    board = []
    for _ in range(size):
        board.append(list(map(int,input().split())))
    answers.append(bfs(board, size))

    size = int(input())

for i, answer in enumerate(answers):
    print('Problem %d: %d' % (i+1, answer))
