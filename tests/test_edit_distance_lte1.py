import unittest
from edit_distance_lte1 import distance


class TestEditDistanceLte1(unittest.TestCase):

    def test_equals(self):
        """"""
        self.assertEqual(distance('', ''), 0)
        self.assertEqual(distance('a', 'a'), 0)
        self.assertEqual(distance('métrique', 'métrique'), 0)

    def test_distance_1(self):
        """"""
        self.assertEqual(distance('', 'a'), 1)
        self.assertEqual(distance('a', ''), 1)
        self.assertEqual(distance('a', 'b'), 1)
        self.assertEqual(distance('a', 'ab'), 1)
        self.assertEqual(distance('ab', 'a'), 1)
        self.assertEqual(distance('metrique', 'métrique'), 1)
        self.assertEqual(distance('distance et rapide', 'distance et rapde'), 1)

    def test_distance_infinite(self):
        """"""
        self.assertEqual(distance('', 'aa'), 7)
        self.assertEqual(distance('ba', ''), 7)
        self.assertEqual(distance('jean', 'jeanot'), 7)
        self.assertEqual(distance('margot', 'jeanot'), 7)
