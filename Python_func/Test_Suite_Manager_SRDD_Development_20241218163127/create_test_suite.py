def create_test_suite(self, name):
        if name in self.test_suites:
            raise ValueError("Test suite already exists.")
        self.test_suites[name] = TestSuite(name)