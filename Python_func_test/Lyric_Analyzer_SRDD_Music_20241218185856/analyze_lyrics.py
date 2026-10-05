def analyze_lyrics(self):
        content_analysis = self.analyze_content()
        sentiment_analysis = self.analyze_sentiment()
        rhyme_scheme_analysis = self.analyze_rhyme_scheme()
        word_frequency_analysis = self.analyze_word_frequency()
        return {
            'content': content_analysis,
            'sentiment': sentiment_analysis,
            'rhyme_scheme': rhyme_scheme_analysis,
            'word_frequency': word_frequency_analysis
        }