def analyze_logs(self):
        print("Analyzing system logs...")
        for root, dirs, files in os.walk(self.log_path):
            for file in files:
                file_path = os.path.join(root, file)
                with open(file_path, 'r') as log_file:
                    for line in log_file:
                        for pattern in self.suspicious_patterns:
                            if re.search(pattern, line, re.IGNORECASE):
                                print(f"Suspicious log entry: {line.strip()}")