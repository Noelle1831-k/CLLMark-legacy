def run(self):
        print("Welcome to MovieMatcher!")
        preferences = self.get_user_preferences()
        recommendations = self.generate_recommendations(preferences)
        self.display_recommendations(recommendations)