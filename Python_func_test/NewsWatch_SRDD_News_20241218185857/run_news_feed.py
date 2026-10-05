def run_news_feed(self):
        '''
        Fetches news and displays the curated feed for the user.
        '''
        articles = self.news_fetcher.fetch_articles(self.user.preferences)
        feed = self.news_feed.generate_feed(articles)
        print("\n--- Your News Feed ---")
        for idx, article in enumerate(feed, start=1):
            print(f"{idx}. {article['title']} - {article['source']}")
            print(f"URL: {article['url']}")
            print("")