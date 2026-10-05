def fetch_articles(self, preferences):
        '''
        Fetches articles by filtering the dummy database based on preferences.
        '''
        language = preferences.get("language", "en")
        categories = preferences.get("categories", [])
        # Simulate fetching articles
        return random.sample(self.dummy_articles, min(len(self.dummy_articles), len(categories)))