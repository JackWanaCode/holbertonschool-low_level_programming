#!/usr/bin/python3


import unittest
island_perimeter = __import__('5-island_perimeter').island_perimeter

class TestCase(unittest.TestCase):
    def test1(self):
        if __name__ == "__main__":
            grid = [
                [0, 0, 0, 0, 0, 0],
                [0, 1, 0, 0, 0, 0],
                [0, 1, 0, 0, 0, 0],
                [0, 1, 1, 1, 0, 0],
                [0, 0, 0, 0, 0, 0]
            ]
            self.assertEqual(island_perimeter(grid), 12)

    def test2(self):
        if __name__ == "__main__":
            grid = [
                        [0, 0, 0, 0, 0, 0],
                        [0, 1, 1, 0, 0, 0],
                        [0, 1, 0, 0, 0, 0],
                        [0, 1, 1, 1, 0, 0],
                        [0, 0, 0, 0, 0, 0]
            ]
            self.assertEqual(island_perimeter(grid), 14)

    def test3(self):
        if __name__ == "__main__":
            grid = [
                        [0, 0, 0, 0, 0, 0],
                        [0, 1, 1, 0, 0, 0],
                        [0, 1, 1, 0, 0, 0],
                        [0, 1, 1, 0, 0, 0],
                        [0, 0, 0, 0, 0, 0]
            ]
            self.assertEqual(island_perimeter(grid), 10)

    def test4(self):
        if __name__ == "__main__":
            grid = [
                        [0, 0, 0, 0, 0, 0],
                        [0, 1, 0, 0, 0, 0],
                        [0, 0, 0, 0, 0, 0],
                        [0, 0, 0, 0, 0, 0],
                        [0, 0, 0, 0, 0, 0]
            ]
            self.assertEqual(island_perimeter(grid), 4)

    def test5(self):
        if __name__ == "__main__":
            grid = [
                        [0, 0, 0, 0, 0, 0],
                        [0, 1, 0, 0, 0, 0],
                        [0, 1, 1, 0, 0, 0],
                        [0, 1, 1, 1, 0, 0],
                        [0, 0, 0, 0, 0, 0]
            ]
            self.assertEqual(island_perimeter(grid), 12)

    def test6(self):
        if __name__ == "__main__":
            grid = [
                [0, 0],
                [0, 0],
            ]
            self.assertEqual(island_perimeter(grid), 0)

    def test7(self):
        if __name__ == "__main__":
            grid = [[0]]
            self.assertEqual(island_perimeter(grid), 0)

    def test8(self):
        if __name__ == "__main__":
            grid = [
                        [0, 0, 0, 0, 0, 0],
                        [0, 0, 0, 0, 0, 0],
                        [0, 0, 1, 0, 0, 0],
                        [0, 0, 0, 0, 0, 0],
                        [0, 0, 0, 0, 0, 0]
            ]
            self.assertEqual(island_perimeter(grid), 4)

    def test9(self):
        if __name__ == "__main__":
            grid = []
            for row in range(100):
                temp = []
                for col in range(100):
                    if (row != 0 and row != 99 and col != 0 and col != 99):
                        temp.append(1)
                    else:
                        temp.append(0)
                grid.append(temp)
            self.assertEqual(island_perimeter(grid), 392)

    def test10(self):
        if __name__ == "__main__":
            grid = [
                        [0, 0, 0, 0, 0, 0],
                        [0, 0, 0, 1, 0, 0],
                        [0, 1, 0, 1, 1, 0],
                        [0, 1, 1, 1, 0, 0],
                        [0, 0, 0, 0, 0, 0]
            ]
            self.assertEqual(island_perimeter(grid), 16)

    def test11(self):
        if __name__ == "__main__":
            grid = [
                        [0]
            ]
            self.assertEqual(island_perimeter(grid), 0)

    def test12(self):
        if __name__ == "__main__":
            grid = [
                        [0, 0]
            ]
            self.assertEqual(island_perimeter(grid), 0)

    def test13(self):
        if __name__ == "__main__":
            grid = [
                        [0, 0, 0, 0, 0, 0],
                        [0, 0, 0, 1, 0, 0],
                        [1, 1, 0, 1, 1, 0],
                        [0, 1, 1, 1, 0, 0],
                        [0, 0, 0, 0, 0, 0]
            ]
            self.assertEqual(island_perimeter(grid), 18)

    def test14(self):
        if __name__ == "__main__":
            grid = [
                        [1, 0, 0, 1, 0, 1],
                        [1, 0, 0, 1, 0, 1],
                        [1, 1, 0, 1, 1, 1],
                        [1, 1, 1, 1, 0, 0],
                        [1, 1, 1, 1, 1, 1]
            ]
            self.assertEqual(island_perimeter(grid), 36)
if __name__ == '__main__':
    unittest.main()
