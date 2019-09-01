def main():
    n = int(input())
    xs, ys, hs = list(), list(), list()
    for i in range(n):
        x, y, h = map(int, input().split())
        xs.append(x)
        ys.append(y)
        hs.append(h)

    for cx in range(101):
        for cy in range(101):
            # In this case,
            # multiple candidates of H & 
            Hs = set()
            Hs_ub = set()
            for x, y, h in zip(xs, ys, hs):
                H_cand = h + abs(x - cx) + abs(y - cy)
                if h == 0:
                    Hs_ub.add(H_cand)
                else:
                    Hs.add(H_cand)

            if len(Hs) != 1:
                continue
            
            # accept No.9, reject 10 - 15
            Hs_rm = set()
            for H in Hs:
                if all([H <= H_ub for H_ub in Hs_ub]):
                    continue
                else:
                    Hs_rm.add(H)
            Hs = Hs - Hs_rm

            Hs = {H for H in Hs if H >= 1}
            if len(Hs) == 1:
                H = Hs.pop()
                print(cx, cy, H)
                return


if __name__ == "__main__":
    main()
    