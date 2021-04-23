import bisect
from collections.abc import Sequence

# copy from bisect.bisect_left
def bisect_left(a, x, lo=0, hi=None):
    """Return the index where to insert item x in list a, assuming a is sorted.

    The return value i is such that all e in a[:i] have e < x, and all e in
    a[i:] have e >= x.  So if x already appears in the list, a.insert(x) will
    insert just before the leftmost x already there.

    Optional args lo (default 0) and hi (default len(a)) bound the
    slice of a to be searched.
    """

    if lo < 0:
        raise ValueError('lo must be non-negative')
    if hi is None:
        hi = len(a)
    while lo < hi:
        mid = (lo+hi)//2
        if a[mid] < x: lo = mid+1
        else: hi = mid
    return lo


def func(x: str, n: int, max_value: int) -> int:
    # int(x, n) if value <= max_value else 0
    x_base = 0
    base = 1
    for i in range(len(x)):
        y = int(x[-i - 1])
        if base > max_value:
            return 0
        if x_base > max_value - y * base:
            return 0
        x_base += y * base
        base *= n
    
    return x_base


class Border(Sequence):
    def __init__(self, func, vmin: int, vmax: int, max_value: int) -> None:
        self.func = func
        self.vmin = vmin
        self.vmax = vmax
        self.max_value = max_value

    def __getitem__(self, index) -> bool:
        value: int = self.vmin + index
        ret = self.func(value, self.max_value)
        if ret == 0:
            return True
        else:
            return ret > self.max_value
    
    def __len__(self) -> int:
        return self.vmax - self.vmin + 1


def main():
    x = input()
    m = int(input())

    d = max(map(int, x))
    if len(x) == 1:
        if int(x) <= m:
            return 1
        else:
            return 0
        
    # len(x) >= 2
    # count False in border=[False, False, True, True, True]
    # see hand_01.txt for max(d + 1, m)
    border = Border(lambda p, max_value: func(x, p, max_value), d + 1, max(d + 1, m), m)
    if len(border) == 0:
        return 0
    return bisect_left(border, True)


print(main())
