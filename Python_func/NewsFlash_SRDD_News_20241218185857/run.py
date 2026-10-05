def run(self):
        news_data = self.fetcher.fetch_news()
        self.search.build_index(news_data)
        categorized_news = self.categorizer.categorize(news_data)
        summarized_news = self.summarizer.summarize(categorized_news)
        personalized_feed = self.preferences.personalize_feed(summarized_news)
        self.display_news(personalized_feed)