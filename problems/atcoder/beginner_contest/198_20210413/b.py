n = int(input())
while n % 10 == 0 and n != 0:
    n = n // 10
        
n_str = str(n)

def is_kaibun(n: str):
    for i in range(len(n_str)):
        if n_str[i] != n_str[-i - 1]:
            return False
    return True

if is_kaibun(n_str):
    print("Yes")
else:
    print("No")
