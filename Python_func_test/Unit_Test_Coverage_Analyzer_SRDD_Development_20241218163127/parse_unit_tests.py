def parse_unit_tests(self, code):
        utils.log_message("Parsing unit tests...")
        test_functions = re.findall(r'def\s+test_(\w+)\s*\(', code)
        utils.log_message(f"Found {len(test_functions)} test functions.")
        return test_functions