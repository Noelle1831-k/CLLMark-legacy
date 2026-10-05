def summarize_article(self, article):
        # Simulate summarization process
        summary = article.content[:50] + "..."
        return NewsArticle(article.title, summary, article.source)