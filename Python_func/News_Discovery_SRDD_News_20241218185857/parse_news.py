def parse_news(self, articles):
        '''
        Parses raw news data into a structured format.
        '''
        print("Parsing news articles...")
        parsed_articles = []
        for article in articles:
            parsed_article = {
                "id": article.get("id"),
                "title": article.get("title"),
                "content": article.get("content"),
                "category": article.get("category"),
                "source": article.get("source"),
                "published_date": article.get("published_date")
            }
            parsed_articles.append(parsed_article)
        print(f"Parsed {len(parsed_articles)} articles.")
        return parsed_articles