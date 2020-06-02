N = int(input())
Hs = list(map(int, input().split()))

def is_large(h_main, hs):
    if len(hs) == 0:
        return True

    for h in hs:
        if h_main < h:
            return False
    return True


ans = 0
for i, H in enumerate(Hs):
    if is_large(H, Hs[:i]):
        ans += 1
print(ans)        
