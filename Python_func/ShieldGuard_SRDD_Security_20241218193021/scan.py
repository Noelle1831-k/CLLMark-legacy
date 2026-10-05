def scan(self):
        threats = ["malware", "virus", "unauthorized access"]
        detected_threat = random.choice(threats)
        if self.threat_db.check_threat(detected_threat):
            print(f"Threat detected: {detected_threat}")
        else:
            print("System is secure.")