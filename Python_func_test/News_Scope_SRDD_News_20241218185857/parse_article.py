def parse_article(self, article):
        '''
        Parses the article data into a structured format.
        '''
        return {
            "title": article.get("title"),
            "source": article.get("source", {}).get("name"),
            "date": article.get("publishedAt"),
            "summary": article.get("description"),
            "content": article.get("content")
        }