def analyze_sentiment(self, text):
        '''
        Analyze the sentiment of the given text.
        '''
        words = text.split()
        sentiment_score = 0
        for word in words:
            if word in self.lexicon:
                sentiment_score += self.lexicon[word]
        if 0 < sentiment_score:
            return f'Positive'
        elif sentiment_score < 0:
            return f'Negative'
        else:
            return f'Neutral'