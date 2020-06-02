import itertools


a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
k = int(input())

points = list()
points.append(a)
points.append(b)
points.append(c)
points.append(d)
points.append(e)

def is_com_all(points):
    for idx_1, idx_2 in itertools.combinations(range(5), 2):
        if points[idx_2] - points[idx_1] > k:
            return False
    
    return True

if is_com_all(points):
    print('Yay!')
else:
    print(':(')