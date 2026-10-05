def detect_intrusion(self, log_line):
        return 'unauthorized access' in log_line.lower()