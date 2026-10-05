def remove_test_case(self, test_case):
        if test_case not in self.test_cases:
            raise ValueError("Test case not found in the suite.")
        self.test_cases.remove(test_case)