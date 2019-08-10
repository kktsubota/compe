n = int(input())
ds = list(map(int, input().split()))

ds = sorted(ds)

print(ds[n // 2] - ds[n // 2 - 1])
