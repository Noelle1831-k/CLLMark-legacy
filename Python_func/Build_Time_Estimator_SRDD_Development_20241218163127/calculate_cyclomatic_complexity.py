def calculate_cyclomatic_complexity(self, file_path):
        try:
            with open(file_path, 'r') as file:
                code_lines = file.readlines()
        except FileNotFoundError:
            return 5  # Default value for non-existent files
        keywords = ["if", "for", "while", "switch", "case"]
        complexity = 1
        for line in code_lines:
            complexity += sum(1 for keyword in keywords if keyword in line)
        return math.log(complexity + 1) * 10  # Scale by logarithm