import unittest

from lib.python.modint import ModInt


class ModIntTest(unittest.TestCase):
    def test_add(self):
        prime = 11
        a = ModInt(5, prime=prime)

        # modint + modint
        b = ModInt(3, prime=prime)
        self.assertEqual((a + b).x, (a.x + b.x) % prime)

        # modint + int
        b = 3
        self.assertEqual((a + b).x, (a.x + b) % prime)

        # modint + negative
        a = ModInt(0, prime=prime)
        b = -1
        self.assertEqual((a + b).x, (a.x + b) % prime)

        a = -1
        b = ModInt(0, prime=prime)
        self.assertEqual((a + b).x, (a + b.x) % prime)

    def test_sub(self):
        prime = 11
        a = ModInt(5, prime=prime)
        b = ModInt(3, prime=prime)
        self.assertEqual((a - b).x, (a.x - b.x) % prime)

        b = 10
        self.assertEqual((a - b).x, (a.x - b) % prime)

        a = 5
        b = ModInt(10, prime=prime)
        self.assertEqual((a - b).x, (a - b.x) % prime)

    def test_mul(self):
        prime = 11
        a = ModInt(5, prime=prime)
        b = ModInt(-3, prime=prime)
        self.assertEqual((a * b).x, (a.x * b.x) % prime)

        a = ModInt(500000, prime=prime)
        b = ModInt(500000, prime=prime)
        self.assertEqual((a * b).x, (a.x * b.x) % prime)

    def test_pow(self):
        prime = 11
        a = ModInt(3, prime=prime)
        b = 30
        self.assertEqual((a ** b).x, (a.x ** b) % prime)
    
    def test_div(self):
        prime = 11
        a = ModInt(10, prime=prime)
        b = 2
        self.assertEqual((a / b).x, (a.x // b) % prime)

        a = 10
        b = ModInt(2, prime=prime)
        self.assertEqual((a / b).x, (a // b.x) % prime)