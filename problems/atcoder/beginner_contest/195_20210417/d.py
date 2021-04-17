import bisect

import numpy as np


def greedy(weights, values, boxes):
    # no item
    if len(weights) == 0:
        return 0
    
    # no box
    if len(boxes) == 0:
        return 0

    # maximum value
    w, v = weights[-1], values[-1]

    # minimum box
    idx = bisect.bisect_left(boxes, w)
    # out of maximum box
    if len(boxes) == idx:
        return greedy(weights[:-1], values[:-1], boxes)
    else:
        boxes.pop(idx)
        return v + greedy(weights[:-1], values[:-1], boxes)


def main():
    n, m, q = map(int, input().split())
    weights = list()
    values = list()
    for _ in range(n):
        w, v = map(int, input().split())
        weights.append(w)
        values.append(v)
    weights = np.array(weights)
    values = np.array(values)
    indices = np.argsort(values)
    weights = weights[indices]
    values = values[indices]

    boxes = list(map(int, input().split()))

    for _ in range(q):
        l, r = map(int, input().split())
        l -= 1
        r -= 1
        boxes_ = sorted(boxes[:l] + boxes[r+1:])
        print(greedy(weights, values, boxes_))


main()
