def analyze(self):
        issues = []
        issues.extend(self.detect_code_smells())
        issues.extend(self.find_unused_variables())
        issues.extend(self.check_long_methods())
        return issues