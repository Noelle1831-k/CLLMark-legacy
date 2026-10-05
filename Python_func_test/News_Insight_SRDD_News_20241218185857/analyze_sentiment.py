def analyze_sentiment(articles):
    # Perform sentiment analysis using TextBlob
    sentiment_analysis = {}
    for article in articles:
        blob = TextBlob(article['content'])
        sentiment_score = blob.sentiment.polarity
        sentiment_analysis[article['title']] = sentiment_score
    return sentiment_analysis