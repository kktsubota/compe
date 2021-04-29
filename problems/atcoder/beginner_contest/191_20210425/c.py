def main():
    h, w = map(int, input().split())

    s = list()
    for i in range(h):
        s.append(list(input()))

    points = set()
    for y in range(h):
        for x in range(w):
            if s[y][x] == "#":
                points.add((y, x))
                points.add((y, x + 1))
                points.add((y + 1, x + 1))
                points.add((y + 1, x))
    
    from collections import defaultdict
    border_points = set()
    border_lines = defaultdict(list)
    # vertical lines
    # (y, x) -> (y + 1, x)
    for y in range(h):
        xs = list()
        for x in range(w + 1):
            if (y, x) in points and (y + 1, x) in points:
                xs.append(x)

        if len(xs) == 0:
            continue
        assert len(xs) >= 2
        p_beg = (y, min(xs))
        p_end = (y + 1, min(xs))
        border_lines[p_beg].append(p_end)
        border_lines[p_end].append(p_beg)
        border_points.add(p_beg)
        border_points.add(p_end)

        p_beg = (y, max(xs))
        p_end = (y + 1, max(xs))
        border_lines[p_beg].append(p_end)
        border_lines[p_end].append(p_beg)
        border_points.add(p_beg)
        border_points.add(p_end)

    # horizontal lines
    # (y, x) -> (y, x + 1)
    for x in range(w):
        ys = list()
        for y in range(h + 1):
            if (y, x) in points and (y, x + 1) in points:
                ys.append(y)
        
        if len(ys) == 0:
            continue
        assert len(ys) >= 2
        p_beg, p_end = (min(ys), x), (min(ys), x + 1)
        border_lines[p_beg].append(p_end)
        border_lines[p_end].append(p_beg)
        border_points.add(p_beg)
        border_points.add(p_end)

        p_beg, p_end = (max(ys), x), (max(ys), x + 1)
        border_lines[p_beg].append(p_end)
        border_lines[p_end].append(p_beg)
        border_points.add(p_beg)
        border_points.add(p_end)
    
    for lines in border_lines:
        assert len(lines) == 2

    border_points = sorted(border_points)
    print(border_points)
    print(border_lines)
    visited = [-1 for _ in range(len(border_points))]
    # most left point
    point_init = border_points[0]
    cnt = 0
    visited[border_points.index(point_init)] = cnt
    prev_move = (0, 0)
    y, x = point_init
    ans = 0
    while -1 in visited:
        for y_, x_ in border_lines[(y, x)]:
            i, j = y_ - y, x_ - x
            idx = border_points.index((y_, x_))
            if visited[idx] != -1:
                continue

            y, x = y_, x_
            cnt += 1
            visited[idx] = cnt
            if (i, j) != prev_move:
                ans += 1
                prev_move = (i, j)
            break
        else:
            raise RuntimeError
    else:
        last_move = point_init[0] - y, point_init[1] - x
        if last_move != prev_move:
            ans += 1

    return ans

print(main())
