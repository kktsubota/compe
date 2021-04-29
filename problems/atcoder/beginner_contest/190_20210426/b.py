n, s, d = map(int, input().split())

X = list()
Y = list()
for i in range(n):
    x, y = map(int, input().split())
    X.append(x)
    Y.append(y)

def find(X, Y) -> bool:
    for x, y in zip(X, Y):
        if x < s and y > d:
            return True
    return False

if find(X, Y):
    print("Yes")
else:
    print("No")
    