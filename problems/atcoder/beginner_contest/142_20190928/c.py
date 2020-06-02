n = int(input())
As = list(map(int, input().split()))

students = [(a, i + 1) for i, a in enumerate(As)]
counts = ' '.join(map(lambda st: str(st[1]), sorted(students)))
print(counts)