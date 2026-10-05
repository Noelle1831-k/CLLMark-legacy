def display_news(articles):
    if not articles:
        print("No articles to display.")
        return
    for article in articles:
        formatted_article = format_article(article)
        print(formatted_article)