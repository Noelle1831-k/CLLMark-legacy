def summarize_all(self, articles):
        summaries = []
        for article in articles:
            summary = self.summarize_article(article)
            summaries.append({"title": article['title'], "summary": summary})
        return summaries