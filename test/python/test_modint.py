import unittest

from lib.python.modint import ModInt


class ModIntTest(unittest.TestCase):
    def test_add(self):
        a = ModInt(5)
        b = ModInt(3)
        self.assertEqual(a + b, ModInt(5 + 3))
