def parse_articles(self, data):
        # Parse the JSON data into a list of articles
        articles = []
        for item in data.get('articles', []):
            article = {
                'id': item.get('source', {}).get('id', ''),
                'title': item.get('title', ''),
                'summary': item.get('description', ''),
                'content': item.get('content', ''),
                'source': item.get('source', {}).get('name', '')
            }
            articles.append(article)
        return articles