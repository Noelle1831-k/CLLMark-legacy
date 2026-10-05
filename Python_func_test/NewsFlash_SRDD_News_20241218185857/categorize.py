def categorize(self, news_data):
        categorized_news = {category: [] for category in self.categories}
        for article in news_data:
            category = self.determine_category(article)
            if category in categorized_news:
                categorized_news[category].append(article)
        return categorized_news