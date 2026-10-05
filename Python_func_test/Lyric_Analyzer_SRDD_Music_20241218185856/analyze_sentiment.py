def analyze_sentiment(self):
        # Use TextBlob for sentiment analysis
        blob = TextBlob(self.lyrics)
        sentiment = blob.sentiment
        return {"polarity": sentiment.polarity, "subjectivity": sentiment.subjectivity}