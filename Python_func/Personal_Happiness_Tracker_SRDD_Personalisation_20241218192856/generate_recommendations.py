def generate_recommendations(self, mood_analysis):
        for mood, count in mood_analysis.items():
            if count > 1:
                self.recommendations.append(f"Consider activities that improve your mood when feeling {mood}.")
            else:
                self.recommendations.append(f"Explore new activities to enhance your mood from {mood}.")
        return self.recommendations