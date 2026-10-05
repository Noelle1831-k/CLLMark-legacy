def analyze_sentiment(lyrics):
    # Determines the emotional tone of the lyrics using TextBlob
    blob = TextBlob(lyrics)
    polarity = blob.sentiment.polarity
    if polarity > 0:
        sentiment_score = "positive"
    elif polarity < 0:
        sentiment_score = "negative"
    else:
        sentiment_score = "neutral"
    return {"sentiment": sentiment_score, "polarity": polarity}