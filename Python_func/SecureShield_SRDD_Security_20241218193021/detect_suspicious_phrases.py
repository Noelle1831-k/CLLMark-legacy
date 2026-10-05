def detect_suspicious_phrases(self, content):
        suspicious_phrases = ["verify your account", "urgent action required"]
        score = 0
        for phrase in suspicious_phrases:
            if phrase in content:
                score += 5
        return score