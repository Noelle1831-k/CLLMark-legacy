def filter_articles(self, articles, preferences):
        '''
        Filters articles based on user preferences.
        '''
        print("Filtering articles...")
        filtered = [article for article in articles if any(topic in article['topics'] for topic in preferences)]
        if not filtered:
            print("No articles match your preferences. Showing random articles.")
            filtered = random.sample(articles, min(len(articles), 3))
        return filtered