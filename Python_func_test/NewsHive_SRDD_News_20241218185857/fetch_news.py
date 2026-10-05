def fetch_news(self):
        articles = self.news_fetcher.fetch_articles(self.user_preferences.get_preferences())
        for article in articles:
            print(f"Title: {article['title']}")
            print(f"Source: {article['source']}")
            print(f"Link: {article['link']}")
            print()