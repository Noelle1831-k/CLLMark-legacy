def filter_news(self, news_data):
        categories = self.user_preferences.preferences.get("categories", [])
        return [news for news in news_data if any(category in news['title'].lower() for category in categories)]