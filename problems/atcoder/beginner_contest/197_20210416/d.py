import math


n = int(input())
x0, y0 = map(int, input().split())
x1, y1 = map(int, input().split())

flag = x0 > x1
if flag:
    x0, x1 = x1, x0
    y0, y1 = y1, y0

# x0 <= x1
cx = (x1 + x0) / 2
cy = (y1 + y0) / 2

dx = (x1 - x0) / 2
dy = (y1 - y0) / 2
r = math.sqrt(dx ** 2 + dy ** 2)
x = r * math.cos(math.pi * 2 / n)
y = r * math.sin(math.pi * 2 / n)

if dx == 0:
    if dy < 0:
        degree = - math.pi / 2
    else:
        degree = math.pi / 2
else:
    # rotate
    degree = math.atan(dy / dx)

# print(x, y, degree, cx, cy)
x_ = math.cos(degree) * x - math.sin(degree) * y + cx
y_ = math.sin(degree) * x + math.cos(degree) * y + cy

if flag:
    # x_, y_: x_{N/2+1}, y_{N/2+1}
    print(x_, y_)
else:
    # x_, y_: x_{N/2+1}, y_{N/2+1}
    print(x_ - (x_ - cx) * 2, y_ - (y_ - cy) * 2)
