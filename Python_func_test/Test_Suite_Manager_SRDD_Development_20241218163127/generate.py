def generate(self, test_suite):
        self.data['suite_name'] = test_suite.name
        self.data['results'] = [test_case.get_result() for test_case in test_suite.test_cases]