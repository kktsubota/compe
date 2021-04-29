def log2_int(x: int):
    cnt = 0
    while x != 1:
        x = x >> 1
        cnt += 1
    return cnt

    
class BinaryIndexTree:
    def __init__(self, arr) -> None:
        # 4 -> 2 -> 1
        # 5 -> 2 -> 1
        # 8 -> 4 -> 2 -> 1
        self.length = len(arr)
        self.bin_size = log2_int(len(arr) - 1) + 2
        self.arr = [0 for _ in range(self.vsize)]
        for i, a in enumerate(arr):
            self.update(i, a)

    @property
    def vsize(self) -> int:
        # virtual size
        return 1 << self.bin_size

    def __len__(self) -> int:
        return self.length

    def get(self, i: int, j=None):
        # sum(arr[i:j])
        if j is None:
            return self._get_sum(i)
        else:
            assert i <= j
            return self._get_sum(j) - self._get_sum(i)
            
    def _get_sum(self, i: int):
        assert 0 <= i <= len(self)
        # return sum(arr[0:i])
        # sum(arr[0:8])
        # = sum(arr[0:4]) + sum(arr[4:6]) + sum(arr[6:7]) +  + sum(arr[7])
        
        ret = 0
        # i = 8 -> arr[i] + 
        for k in range(self.bin_size):
            index = (i >> k)
            if (index & 1) == 1:
                offset = self.vsize - (self.vsize >> k)
                ret += self.arr[offset + index]
        return ret

    def update(self, i: int, x):
        diff = x - self.arr[i + 1]
        for k in range(self.bin_size):
            offset = self.vsize - (self.vsize >> k) + 1
            index = i >> k
            self.arr[index + offset] += diff
        
        # unused
        assert self.arr[0] == 0
    
arr = [1, 5, 2, 3, 12, 8]
tree = BinaryIndexTree(arr)
print(tree.arr)
for i in range(len(tree) + 1):
    print(i, tree._get_sum(i))

# for i in range(len(tree)):
#     print(i, tree.get(i, i + 1))
