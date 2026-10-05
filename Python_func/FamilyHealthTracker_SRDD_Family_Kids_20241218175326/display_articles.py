def display_articles(self):
        for article in self.articles:
            print(f"Title: {article['title']}\nContent: {article['content']}\n")