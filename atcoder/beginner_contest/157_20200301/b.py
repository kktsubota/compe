A = list()
for i in range(3):
    A.append(list(map(int, input().split())))

n = int(input())
bs = [int(input()) for i in range(n)]

bingo = [[False for i in range(3)] for j in range(3)]

def hit(b):
    for i in range(3):
        for j in range(3):
            if A[i][j] == b:
                return (i, j)
    return None
for b in bs:
    ret = hit(b)                
    if ret is None:
        continue
    else:
        bingo[ret[0]][ret[1]] = True

def detect():
    for i in range(3):
        if all(bingo[i]):
            return True
    
    for j in range(3):
        if all([bingo[i][j] for i in range(3)]):
            return True
    
    if bingo[0][0] and bingo[1][1] and bingo[2][2]:
        return True

    if bingo[2][0] and bingo[1][1] and bingo[0][2]:
        return True

    return False

if detect():
    print('Yes')
else:
    print('No')
