def scan_processes(self):
        for proc in psutil.process_iter(['pid', 'name', 'username']):
            if self.detect_suspicious_process(proc):
                self.suspicious_processes.append(proc.info)
                print(f"Suspicious process detected: {proc.info}")
                self.threat_manager.quarantine_threat(proc.info)