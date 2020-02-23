n = int(input())
A = list(map(int, input().split()))

def func():
    for a in A:
        if a % 2 == 0:
            if a % 3 == 0 or a % 5 == 0:
                continue
            else:
                return False
    
    return True

if func():
    print('APPROVED')
else:
    print('DENIED')
    