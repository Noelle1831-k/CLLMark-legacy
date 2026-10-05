def prioritize_test_cases(self):
        self.test_cases.sort(key=lambda x: x.priority, reverse=True)