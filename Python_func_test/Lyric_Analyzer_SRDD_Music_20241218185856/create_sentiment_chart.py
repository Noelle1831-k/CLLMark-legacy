def create_sentiment_chart(self):
        # Create a pie chart for sentiment analysis
        sentiment = self.analysis_results['sentiment']
        labels = ['Polarity', 'Subjectivity']
        sizes = [sentiment['polarity'], sentiment['subjectivity']]
        plt.figure(figsize=(6, 6))
        plt.pie(sizes, labels=labels, autopct='%1.1f%%', startangle=140)
        plt.title('Sentiment Analysis')