	int i = 0;
	while (i < nums.size()) {
		if (nums[i] % 2 != 0) {
			return nums[i];
		}
		i++;
	}
	return 0;
}
"""
class Test(unittest.TestCase):
    def test_first_odd(self):
        self.assertEqual(first_odd([1, 3, 5]), 1)
        self.assertEqual(first_odd([2, 4, 1, 3]), 1)
        self.assertEqual(first_odd([1, 2, 3, 4, 5, 6, 7, 8, 9]), 1)
        self.assertEqual(first_odd([1, 3, 5, 8, 10]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12, 14]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12, 14, 16]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12, 14, 16, 18]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12, 14, 16, 18, 20]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54]), 1)
        self.assertEqual(first_odd([2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56]), 