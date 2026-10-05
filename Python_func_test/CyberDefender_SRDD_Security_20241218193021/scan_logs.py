def scan_logs(self):
        for _ in range(50):
            log_entry = self._generate_random_log()
            self.logs.append(log_entry)
            if self._is_suspicious(log_entry):
                print(f"Suspicious log entry detected: {log_entry}", flush=True)