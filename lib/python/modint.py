class ModInt(object):
    prime = 1000000007

    def __init__(self, x, calc_mod=True):
        assert isinstance(x, int)
        if calc_mod:
            self.x = x % self.prime
        else:
            self.x = x
    
    def __add__(self, y):
        assert isinstance(y, ModInt)
        assert self.prime == y.prime
        z = ModInt(0, calc_mod=False)
        z.x = self.x + y.x
        if z.x >= self.prime:
            z.x -= self.prime
        return z
    
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

    def __eq__(self, y):
        return self.prime == y.prime and self.x == y.x

    def __str__(self):
        return '{} (mod {})'.format(self.x, self.prime)
