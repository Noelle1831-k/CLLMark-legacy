def analyze_mood(self, user_data):
        self.mood_data.append(user_data['mood'])
        return self.detect_trends()