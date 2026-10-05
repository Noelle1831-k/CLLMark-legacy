def generate_recommendations(self, user_preferences, articles):
        # Generate recommendations based on user preferences and trained model
        recommendations = []
        for article in articles:
            score = self._calculate_relevance_score(article, user_preferences)
            if score > 0.5:  # Threshold for recommendation
                recommendations.append(article)
        return recommendations