def apply_preferences(self, articles):
        '''
        Applies user preferences to filter the list of articles.
        '''
        print("Applying user preferences to filter articles...")
        filtered_articles = [article for article in articles if self._matches_preferences(article)]
        return filtered_articles