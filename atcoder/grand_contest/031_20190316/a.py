n = int(input())
s = input()

alphabet_place = dict()
for idx, c in enumerate(s):
    if c in alphabet_place:
        alphabet_place[c].append(idx)
    else:
        alphabet_place[c] = [idx]

ans = 1
for alph, place in alphabet_place.items():
    # +1: unuse
    ans = (len(place) + 1) * ans

# all unuse
ans = ans - 1
print(ans % (10**9+7))