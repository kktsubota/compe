import copy


def count(s):
    s = list(s)
    cnt = 0
    for i in range(1, len(s)):
        if s[i] == s[i-1]:
            s[i] = '*'
            cnt += 1
    return cnt


def main():
    S = input()
    K = int(input())
    if len(set(S)) == 1:
        return (len(S) * K) // 2

    else:
        n1 = count(S)
        n2 = count(S + S)
        return (K - 1) * (n2 - n1) + n1
            

if __name__ == "__main__":
    print(main())
