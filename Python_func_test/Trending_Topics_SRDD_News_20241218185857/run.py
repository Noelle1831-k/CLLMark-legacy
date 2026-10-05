def run(self):
        platforms = ['twitter', 'facebook', 'instagram']
        for platform in platforms:
            try:
                raw_trending = self.api.fetch_trending_topics(platform)
                processed_trending = self.processor.process_trending_data(raw_trending)
                self.dashboard.display_trending_topics(processed_trending)
                raw_news = self.api.fetch_news_articles(platform)
                processed_news = self.processor.process_news_data(raw_news)
                self.dashboard.display_news_articles(processed_news)
            except Exception as e:
                print(f"Error processing data for {platform}: {e}")