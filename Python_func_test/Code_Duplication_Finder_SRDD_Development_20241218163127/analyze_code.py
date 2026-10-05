def analyze_code(self, files):
        code_segments = []
        for filename, lines in files:
            for i, line in enumerate(lines):
                if line.strip():
                    code_segments.append((filename, i, line.strip()))
        return code_segments