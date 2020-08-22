h, w, m = map(int, input().split())

count_h = [0 for i in range(h)]
count_w = [0 for i in range(w)]
points = set()
for i in range(m):
    y, x = map(int, input().split())
    y -= 1
    x -= 1
    points.add((y, x))
    count_h[y] += 1
    count_w[x] += 1

ch_max, cw_max = max(count_h), max(count_w)
ys = [y for y in range(len(count_h)) if count_h[y] == ch_max]
xs = [x for x in range(len(count_w)) if count_w[x] == cw_max]

    
ans = ch_max + cw_max
if len(ys) * len(xs) <= m:
    def _find():
        for x in xs:
            for y in ys:
                if (y, x) not in points:
                    return True
        return False
    if not _find():
        ans -= 1
print(ans)
