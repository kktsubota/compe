def main():
    k = int(input())
    d = dict()

    # 2 ** 20 = 10 ** 6
    order = 0
    find = False
    for n_digit in range(1, 20):
        # print('(n_digit, order):', n_digit, order)
        if n_digit == 1:
            for i in range(10):
                d[(n_digit, i)] = 1
            
        else:
            for i in range(10):
                d[(n_digit, i)] = d[(n_digit - 1, i)]
                if i >= 1:
                    d[(n_digit, i)] += d[(n_digit - 1, i - 1)]
                if i <= 8:
                    d[(n_digit, i)] += d[(n_digit - 1, i + 1)]

        for i in range(1, 10):
            if order + d[(n_digit, i)] < k:
                order += d[(n_digit, i)]
            else:
                find = True
            
            if find:
                break

        if find:
            break

    # n_digit, start with i
    ans = list()
    ans.append(i)

    for digit in range(n_digit - 1, 0, -1):
        for j in range(i - 1, i + 2):
            if 0 <= j <= 9:
                if order + d[(digit, j)] < k:
                    order += d[(digit, j)]
                else:
                    ans.append(j)
                    i = j
                    break

    print(''.join(map(str, ans)))


main()