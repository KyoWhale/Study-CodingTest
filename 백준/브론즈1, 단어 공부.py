# 15:25 ~ 

s = input().upper()

is_multiple = False
max_count, max_c = 0, 'A'
for i in range(26):
    c = chr(i+65)
    
    count = s.count(c)
    if count > max_count:
        max_count, max_c = count, c
        is_multiple = False
    elif count == max_count:
        is_multiple = True

if is_multiple:
    print("?")
else:
    print(max_c)