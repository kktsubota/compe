def main():
    n = int(input())
    s = input()
    if n % 2 == 1:
        return False
    
    i = n // 2
    if s[:i] == s[i:]:
        return True
    else:
        return False


if __name__ == "__main__":
    if main():
        print('Yes')
    else:
        print('No')