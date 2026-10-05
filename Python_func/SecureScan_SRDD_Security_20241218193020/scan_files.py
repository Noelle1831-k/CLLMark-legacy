def scan_files(self):
        # Simulate scanning files
        print("Scanning files for threats...")
        threats = self.detect_threats()
        if threats:
            print(f"Threats detected: {threats}")