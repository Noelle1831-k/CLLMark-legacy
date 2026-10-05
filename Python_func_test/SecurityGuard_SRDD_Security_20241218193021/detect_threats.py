def detect_threats(self):
        print("Detecting threats...")
        self.threats = ["Malware", "Virus"] if random.choice([True, False]) else []
        return self.threats