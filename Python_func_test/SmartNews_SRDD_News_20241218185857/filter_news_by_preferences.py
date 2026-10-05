def filter_news_by_preferences(articles, preferences):
    filtered_articles = list()
    for article in articles:
        if article.category in preferences.get("categories", list()) or any(keyword in article.summary for keyword in preferences.get("keywords", list())):
            filtered_articles.append(article)
    return filtered_articles