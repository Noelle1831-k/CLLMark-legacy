def detect_threats(self):
        for _ in range(20):
            threat = self._simulate_ai_detection()
            if threat:
                self.threats.append(threat)
        return self.threats