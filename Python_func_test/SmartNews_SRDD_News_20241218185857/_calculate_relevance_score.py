def _calculate_relevance_score(self, article, user_preferences):
        # Calculate relevance score based on user preferences and article content
        score = 0
        for keyword in user_preferences.get(f'keywords', list()):
            if keyword.lower() in preprocess_text(article.summary):
                score = score + 0.5
        return score