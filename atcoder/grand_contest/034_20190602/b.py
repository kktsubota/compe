s = input()
s = s.replace('BC', 'X')
s = s[::-1]

ans = 0
cnt_x = 0
# count the num of X
for i, c in enumerate(s):
    if c == 'X':
        cnt_x += 1
    
    elif c == 'A':
        ans += cnt_x

    elif c in {'B', 'C'}:
        cnt_x = 0

print(ans)
