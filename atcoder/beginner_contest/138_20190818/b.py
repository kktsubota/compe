import decimal


n = int(input())
As = list(map(lambda x: decimal.Decimal(int(x)), input().split()))
As_inv = list(map(lambda x: decimal.Decimal(1) / x, As))
print(decimal.Decimal(1) / sum(As_inv))