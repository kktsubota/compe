class ModInt(object):
    def __init__(self, x, prime=1000000007, calc_mod=True):
        assert isinstance(x, int)
        self.prime = prime
        if calc_mod:
            self.x = x % self.prime
        else:
            self.x = x
    
    def __add__(self, y):
        if isinstance(y, ModInt):
            assert self.prime == y.prime
            z = ModInt(self.x + y.x, prime=self.prime, calc_mod=False)
            if z.x >= self.prime:
                z.x -= self.prime
        elif isinstance(y, int):
            z = ModInt(self.x + y, prime=self.prime)
        else:
            raise NotImplementedError('should be int or ModInt')
        return z

    def __radd__(self, y):
        return ModInt(y, prime=self.prime) + self

    def __sub__(self, y):
        if isinstance(y, ModInt):
            assert self.prime == y.prime
            z = ModInt(self.x - y.x, prime=self.prime, calc_mod=False)
            if z.x < 0:
                z.x += self.prime
        elif isinstance(y, int):
            z = ModInt(self.x - y, prime=self.prime)
        else:
            raise NotImplementedError('should be int or ModInt')
        return z
    
    def __rsub__(self, y):
        return ModInt(y, prime=self.prime) - self

    def __mul__(self, y):
        if isinstance(y, ModInt):
            assert self.prime == y.prime
            y = ModInt(self.x * y.x, prime=self.prime)
        elif isinstance(y, int):
            y = ModInt(self.x * y, prime=self.prime)
        else:
            raise NotImplementedError('should be int or ModInt')
        return y
    
    def __rmul__(self, y):
        return ModInt(y, prime=self.prime) * self
    
    def __pow__(self, y):
        if isinstance(y, ModInt):
            y = y.x
        assert isinstance(y, int)
        if y < 0:
            return ModInt(1, prime=self.prime, calc_mod=False) / self.__pow__(-y)
        elif y == 0:
            return ModInt(1, prime=self.prime, calc_mod=False)
        else:
            # y = 2 * z + {0,1}
            z = self.__pow__(y >> 1)
            z = z * z
            if (y & 1) == 0:
                return z
            else:
                return self * z

    def __truediv__(self, y):
        if isinstance(y, int):
            y = ModInt(y, prime=self.prime)
        assert isinstance(y, ModInt)
        # Fermat's little theorem
        # y ** (p - 1) % p == 1
        # y ** (p - 2) % p == 1 / y
        y_inv = (y ** (self.prime - 2))
        return self * y_inv
    
    def __rtruediv__(self, y):
        return ModInt(y, prime=self.prime) / self

    def __floordiv__(self, y):
        raise NotImplementedError

    def __eq__(self, y):
        if isinstance(y, int):
            y = ModInt(y, prime=self.prime)
        return self.prime == y.prime and self.x == y.x

    def __str__(self):
        return '{} (mod {})'.format(self.x, self.prime)
