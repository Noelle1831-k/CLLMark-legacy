def add_test_case(self, test_case):
        if not isinstance(test_case, TestCase):
            raise TypeError("Invalid test case.")
        self.test_cases.append(test_case)