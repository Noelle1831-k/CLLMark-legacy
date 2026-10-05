def detect_trends(self):
        mood_trends = {}
        for mood in self.mood_data:
            if mood in mood_trends:
                mood_trends[mood] += 1
            else:
                mood_trends[mood] = 1
        return mood_trends