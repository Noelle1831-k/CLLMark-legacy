def view_saved_articles(self):
        saved_articles = self.article_manager.get_saved_articles()
        for article in saved_articles:
            print(f"Title: {article['title']}")
            print(f"Source: {article['source']}")
            print(f"Link: {article['link']}")
            print()