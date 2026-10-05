def _simulate_ai_detection(self):
        if random.random() > 0.8:
            return {"type": "malware", "severity": random.choice(["low", "medium", "high"])}
        return None