class ModInt(object):
    prime = 1000000007

    def __init__(self, x, calc_mod=True):
        if calc_mod:
            self.x = x % self.prime
        else:
            self.x = x
    
    def __add__(self, y):
        assert isinstance(y, ModInt)
        y = self.x + y.x
        if y.x >= self.prime:
            y.x -= self.prime
        return y
    
    def __sub__(self, y):
        assert isinstance(y, ModInt)
        y.x = self.x - y.x
        if y.x < 0:
            y.x += self.prime
        return y
    
    def __mul__(self, y):
        assert isinstance(y, ModInt)
        y = ModInt(self.x * y.x)
        return y
    
    def __pow__(self, y):
        if isinstance(y, ModInt):
            y = y.x
        assert isinstance(y, int) and y >= 0
        if y == 0:
            return ModInt(1, calc_mod=False)
        else:
            # y = 2 * z + {0,1}
            z = self.__pow__(y >> 1)
            z = z * z
            if (y & 1) == 0:
                return z
            else:
                return self * z

    def __truediv__(self, y):
        assert isinstance(y, ModInt)
        # Fermat's little theorem
        # y ** (p - 1) % p == 1
        # y ** (p - 2) % p == 1 / y
        return self * (y ** (self.prime - 2))
    
    def __floordiv__(self, y):
        raise NotImplementedError

    def __str__(self):
        return '{} (mod {})'.format(self.x, self.prime)


def main():
    a = ModInt(10, calc_mod=False)
    print(a, type(a))
    print(a.x, type(a.x))
    print(a ** 0)
    print(a ** 9)
    print(a ** a)
    print('Fermat. start')
    print(a ** (a.prime - 1))
    print(a ** (a.prime))
    print('Fermat. end')
    print(ModInt(10 ** 10))
    print(a / ModInt(3))
    print(a / ModInt(2))
    print(a.x // 2)
    a *= ModInt(1000000000)
    print(a)

    # import ipdb; ipdb.set_trace()
    # 10C2
    def comb(n, k):
        child = ModInt(1)
        for i in range(1, n + 1):
            child *= ModInt(i)
        parent = ModInt(1)
        for i in range(1, k + 1):
            parent /= ModInt(i)
        for i in range(1, n - k + 1):
            parent /= ModInt(i)
        
        return child * parent

    print(comb(10, 2))


if __name__ == "__main__":
    main()
