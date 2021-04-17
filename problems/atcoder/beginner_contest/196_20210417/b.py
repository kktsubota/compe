x = input()
index = x.find(".")
if index == -1:
    print(x)
else:
    print(x[:index])
    