def parse_news_data(raw_data):
    articles = []
    for item in raw_data.get('articles', []):
        article = {
            'title': item.get('title', 'No Title'),
            'description': item.get('description', 'No Description'),
            'url': item.get('url', '#')
        }
        articles.append(article)
    utils.log_info(f"Parsed {len(articles)} articles")
    return articles