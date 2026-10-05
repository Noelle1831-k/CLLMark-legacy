def parse_news(self, news_json):
        # Parse the JSON response to extract news articles
        articles = []
        for item in news_json['articles']:
            articles.append({
                'title': item['title'],
                'content': item['content'],
                'source': item['source']['name']
            })
        return articles