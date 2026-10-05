def quarantine_threat(self, threat):
        self.quarantined_threats.append(threat)
        print(f"Threat quarantined: {threat}")