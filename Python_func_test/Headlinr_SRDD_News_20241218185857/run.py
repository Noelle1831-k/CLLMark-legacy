def run(self):
        self.user_preferences.update_preferences()
        self.articles = news.fetch_articles()
        summarized_articles = [self.summarizer.summarize_article(article) for article in self.articles]
        ranked_articles = self.ranker.rank_articles(summarized_articles, self.user_preferences)
        self.display_articles(ranked_articles)