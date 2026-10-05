def get_test_suite(self, name):
        if name not in self.test_suites:
            raise ValueError("Test suite does not exist.")
        return self.test_suites[name]