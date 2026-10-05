def detect_unauthorized_access(self):
        print("Detecting unauthorized access attempts...")
        for device in self.devices:
            time.sleep(1)  # Simulate detection time
            unauthorized_access = random.choice([True, False])
            if unauthorized_access:
                print(f"Unauthorized access attempt detected on {device}.")
            else:
                print(f"No unauthorized access detected on {device}.")
        print("Unauthorized access detection completed.")