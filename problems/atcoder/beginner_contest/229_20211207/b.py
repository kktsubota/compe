def main():
    a, b = input().split()

    for i in range(min(len(a), len(b))):
        if int(a[-i - 1]) + int(b[-i - 1]) > 9:
            return False
    
    return True

if main():
    print("Easy")
else:
    print("Hard")
