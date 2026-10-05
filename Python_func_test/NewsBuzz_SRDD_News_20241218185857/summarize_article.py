def summarize_article(self, article):
        try:
            return summarize(article['content'], word_count=50)
        except ValueError:
            return article['content'][:150]