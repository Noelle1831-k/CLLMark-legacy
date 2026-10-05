def display_news_articles(self, articles):
        print("\nNews Articles:", flush=True)
        for article in articles:
            print(f"- {article}", flush=True)