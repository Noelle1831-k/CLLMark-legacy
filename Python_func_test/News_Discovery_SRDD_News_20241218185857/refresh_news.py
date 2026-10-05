def refresh_news(self):
        '''
        Refreshes the news articles by clearing the database and fetching new articles.
        '''
        print("Refreshing news articles...")
        self.database.clear_articles()
        self.fetch_news()
        print("News articles refreshed.")