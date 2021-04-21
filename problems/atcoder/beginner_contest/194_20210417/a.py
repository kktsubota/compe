a, b = map(int, input().split())

nyuuko = a + b
nyuushi = b

if nyuuko >= 15 and nyuushi >= 8:
    print("1")
elif nyuuko >= 10 and nyuushi >= 3:
    print("2")
elif nyuuko >= 3:
    print("3")
else:
    print("4")