import itertools
import queue
import copy


def calc_dist(S, points, p_s, p_e):
    h, w = len(S), len(S[0])
    distance = {p: -1 for p in points}
    que = queue.Queue()
    que.put((p_s, 0))
    while not que.empty():
        p, d = que.get()
        y, x = p

        if not (0 <= x < w and 0 <= y < h):
            continue
        if S[y][x] == '#':
            continue

        if distance[p] != -1:
            continue

        distance[p] = d
        if p == p_e:
            break

        que.put(((y, x - 1), d + 1))
        que.put(((y, x + 1), d + 1))
        que.put(((y - 1, x), d + 1))
        que.put(((y + 1, x), d + 1))
    
    # print(p_s, p_e, distance[p_e])
    # Svis = copy.deepcopy(S)
    # Svis[p_s[0]][p_s[1]] = 'S'
    # Svis[p_e[0]][p_e[1]] = 'E'
    # for e in Svis:
    #     print(''.join(e))
    return distance[p_e]


def main():
    h, w = map(int, input().split())

    S = list()
    for y in range(h):
        S.append(list(input()))
    points = [(y, x) for y, x in itertools.product(range(h), range(w)) if S[y][x] == '.']

    # print(calc_dist(S, points, (0, 2), (1, 0)))
    distance = list()
    for p_s, p_e in itertools.combinations(points, 2):
        d = calc_dist(S, points, p_s, p_e)
        distance.append(d)

    print(max(distance))


main()
