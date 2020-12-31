a, b, c, d = map(int, input().split())

if b < c:
    print("No")

elif b > c and d < a:
    print("No")

else:
    print("Yes")
