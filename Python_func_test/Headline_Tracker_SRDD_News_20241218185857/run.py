def run(self):
        news_sources = ["source1", "source2", "source3"]
        for source in news_sources:
            news_data = self.fetcher.fetch_news(source)
            parsed_news = self.fetcher.parse_news(news_data)
            self.dashboard.display_news(parsed_news)
        self.updater.schedule_updates(60, self.fetcher, news_sources, self.dashboard)