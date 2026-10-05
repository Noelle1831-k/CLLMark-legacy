def delete_test_suite(self, name):
        if name not in self.test_suites:
            raise ValueError('Test suite does not exist.')
        del self.test_suites[name]