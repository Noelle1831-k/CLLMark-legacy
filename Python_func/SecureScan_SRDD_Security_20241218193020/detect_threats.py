def detect_threats(self):
        # Simulate threat detection with random chance
        threats = ["malware", "ransomware", "suspicious file"]
        detected = [threat for threat in threats if random.choice([True, False])]
        return detected