def summarize(self, categorized_news):
        for category, articles in categorized_news.items():
            for article in articles:
                article["summary"] = self.generate_summary(article)
        return categorized_news