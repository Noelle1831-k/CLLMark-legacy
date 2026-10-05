def compile_digest(self, news_data):
        filtered_news = self.filter_news(news_data)
        return "\n".join([f"{news['title']} - {news['link']}\nDescription: {news['description']}" for news in filtered_news])