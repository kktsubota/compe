X = int(input())
num_500 = X // 500
X = X % 500
num_5 = X // 5
print(num_500 * 1000 + num_5 * 5)
