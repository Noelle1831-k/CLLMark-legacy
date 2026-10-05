def check(self, code_lines):
        issues = list()
        declared_variables = set()
        used_variables = set()
        variable_pattern = re.compile(r"\b(\w+)\b")
        for line in code_lines:
            if "=" in line:
                declared_variables.update(variable_pattern.findall(line.split("=")[0]))
            used_variables.update(variable_pattern.findall(line))
        unused_variables = declared_variables - used_variables
        for variable in unused_variables:
            issues.append(f"Unused variable: {variable}")
        return issues