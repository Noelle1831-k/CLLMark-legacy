def fetch_news(self):
        '''
        Fetches news articles from all configured sources and stores them in the database.
        '''
        print("Fetching news from all sources...")
        for source in self.sources:
            print(f"Fetching from {source.name}...")
            articles = source.fetch_from_source()
            parsed_articles = self.parse_news(articles)
            self.store_news(parsed_articles)
        print("All news fetched and stored successfully.")