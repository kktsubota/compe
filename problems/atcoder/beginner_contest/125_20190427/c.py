N = int(input())
As = list(map(int, input().split()))


def gcd(a, b):
    if a < b:
        a, b = b, a
    assert a >= b
    r = a % b
    if r == 0:
        return b
    
    else:
        return gcd(b, r)


gcd_list_l = list()
gcd_list_r = list()

for i in range(0, N):
    if i == 0:
       value = As[i]
    else:
        value = gcd(gcd_list_l[-1], As[i])
    
    gcd_list_l.append(value)

for i in range(N)[::-1]:
    if i == N - 1:
        value = As[i]
    else:
        value = gcd(gcd_list_r[-1], As[i])
    gcd_list_r.append(value)

gcd_list_r.reverse()

# print(gcd_list_l)
# print(gcd_list_r)

ans = 0
for i in range(N):
    if i == 0:
        value = gcd_list_r[i + 1]
    elif i == N - 1:
        value = gcd_list_l[i - 1]
    else:
        value = gcd(gcd_list_l[i - 1], gcd_list_r[i + 1])
    
    ans = max(value, ans)
print(ans)