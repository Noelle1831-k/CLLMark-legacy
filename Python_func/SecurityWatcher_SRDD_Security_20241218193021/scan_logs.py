def scan_logs(self):
        log_files = ['/var/log/syslog', '/var/log/auth.log']
        for log_file in log_files:
            if os.path.exists(log_file):
                with open(log_file, 'r') as f:
                    for line in f:
                        if self.detect_intrusion(line):
                            self.suspicious_logs.append(line)
                            print(f"Intrusion attempt detected: {line}")