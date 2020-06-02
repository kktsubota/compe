import math


a, b, h, m = map(int, input().split())

theta_a = 2 * math.pi * (h + m / 60) / 12
theta_b = 2 * math.pi * m / 60

c2 = a ** 2 + b ** 2 - 2 * a * b * math.cos(theta_b - theta_a)
print(str(math.sqrt(c2)))
