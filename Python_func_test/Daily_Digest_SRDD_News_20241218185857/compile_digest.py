def compile_digest(self, news_data):
        filtered_news = self.filter_news(news_data)
        return f"\n".join([f"{news[f'title']} - {news[f'link']}\nDescription: {news[f'description']}" for news in filtered_news])