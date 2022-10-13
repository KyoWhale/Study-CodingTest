# 17:37 ~ 17:59 pypy3는 시간복잡도에서는 좋지만 공간복잡도에서 좋지 않아 메모리 초과가 뜸
import sys

MAX = 21
counter = [0] * MAX

for _ in range(int(sys.stdin.readline())):
    raw_op = sys.stdin.readline().split()
    if raw_op[0] == 'all':
        for i in range(MAX):
            counter[i] = 1
        continue
    elif raw_op[0] == 'empty':
        for i in range(MAX):
            counter[i] = 0
        continue
    
    num = int(raw_op[1])
    if raw_op[0] == 'add':
        counter[num] = 1
    elif raw_op[0] == 'remove':
        counter[num] = 0
    elif raw_op[0] == 'check':
        print(counter[num])
    elif raw_op[0] == 'toggle':
        if counter[num]:
            counter[num] = 0
        else:
            counter[num] = 1