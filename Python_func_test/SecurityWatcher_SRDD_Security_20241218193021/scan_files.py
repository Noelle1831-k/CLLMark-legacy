def scan_files(self):
        for root, dirs, files in os.walk('/'):
            for file in files:
                if self.detect_malware(file):
                    self.suspicious_files.append(file)
                    print(f"Malware detected in file: {file}")
                    self.threat_manager.quarantine_threat(file)