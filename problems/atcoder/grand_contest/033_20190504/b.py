H, W, N = map(input().split())
sr, sc = map(input().split())
S = input()
T = input()


position = (sr, sc)
def judge(position, ):
    for i in range(N):
        if S[i] == 'L':
            if position[0] == 0:
                return True

if judge(position):
    print('YES')
else:
    print('NO')