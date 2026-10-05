def generate_test_cases(self, input_file):
        with open(input_file, 'r') as file:
            code = file.read()
        functions = parse_code(code)
        for func in functions:
            self.test_cases.extend(self._generate_cases_for_function(func))
        return self.test_cases