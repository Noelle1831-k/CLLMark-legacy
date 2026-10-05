def parse_article(self, article_data):
        # Simulate parsing article data
        return {
            'title': article_data.get('title', 'No Title'),
            'source': article_data.get('source', 'Unknown Source'),
            'link': article_data.get('link', 'No Link')
        }