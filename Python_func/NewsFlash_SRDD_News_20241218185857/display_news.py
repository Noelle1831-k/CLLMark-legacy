def display_news(self, news_feed):
        for category, articles in news_feed.items():
            print(f"Category: {category}")
            for article in articles:
                print(f"Title: {article['title']}")
                print(f"Summary: {article['summary']}\n")