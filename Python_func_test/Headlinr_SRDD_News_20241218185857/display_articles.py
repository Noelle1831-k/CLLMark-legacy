def display_articles(self, articles):
        for article in articles:
            print(f"Title: {article.title}\nSummary: {article.summary}\n")
            self.bookmark_manager.add_bookmark(article)
            features.share_article(article)