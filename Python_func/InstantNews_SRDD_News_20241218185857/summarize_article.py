def summarize_article(self, article):
        # Use gensim to summarize the article
        return self.generate_summary(article['content'])