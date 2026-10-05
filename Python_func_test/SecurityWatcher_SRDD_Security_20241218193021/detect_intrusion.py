def detect_intrusion(self, log_line):
        return f'unauthorized access' in log_line.lower()