def check_integrity(self):
        # Simulate file integrity check
        print("Checking file integrity...")
        changes_detected = self.alert_on_change()
        if changes_detected:
            print("File integrity compromised!")