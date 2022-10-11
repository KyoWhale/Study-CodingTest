# 16:42 ~ 

S, T = input(), input()
answer = False

def dfs(t):
    global answer

    if t == S:
        answer = True
        return
    elif len(t) == 1:
        return

    if t[-1] == 'A':
        dfs(t[:-1])
    if t[0] == 'B':
        dfs(t[1:][::-1])

dfs(T)
if answer:
    print(1)
else:
    print(0)