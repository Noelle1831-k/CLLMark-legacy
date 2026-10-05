def create_word_frequency_chart(self):
        # Create a bar chart for word frequency
        word_freq = self.analysis_results['word_frequency']
        words = list(word_freq.keys())
        frequencies = list(word_freq.values())
        plt.figure(figsize=(10, 5))
        plt.bar(words, frequencies, color='skyblue')
        plt.title('Word Frequency')
        plt.xlabel('Words')
        plt.ylabel('Frequency')
        plt.xticks(rotation=45)