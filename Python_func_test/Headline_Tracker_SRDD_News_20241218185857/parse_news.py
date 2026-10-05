def parse_news(self, data):
        if not data:
            return []
        headlines = []
        for item in data.get('articles', []):
            headlines.append(item.get('title', 'No Title'))
        return headlines