def is_recommended(self, movie):
        # Simulate a recommendation decision based on user preferences and movie attributes
        similarity_score = calculate_similarity(self.user_profile.preferences, movie)
        return similarity_score > 0.5 and movie[f'id'] not in self.user_profile.history