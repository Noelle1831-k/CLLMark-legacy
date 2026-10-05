def generate_digest(self, user_id, articles, preferences):
        # Filter articles based on user preferences
        filtered_articles = [article for article, summary, category in articles if self._article_matches_preferences(category, preferences)]
        # Simulate digest generation with filtered content
        digest_content = [f"{summary} ({category})" for article, summary, category in filtered_articles[:3]]  # Example: return top 3 articles
        return f"Digest for {user_id}: {digest_content}"