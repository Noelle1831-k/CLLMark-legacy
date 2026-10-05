def main():
    # Fetch news articles
    articles = news_fetcher.fetch_news()
    # Analyze content
    content_analysis = content_analyzer.analyze_content(articles)
    # Analyze sentiment
    sentiment_analysis = sentiment_analyzer.analyze_sentiment(articles)
    # Analyze popularity
    popularity_analysis = popularity_analyzer.analyze_popularity(articles)
    # Display results on dashboard
    dashboard.display_dashboard(content_analysis, sentiment_analysis, popularity_analysis)