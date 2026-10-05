def analyze_word_frequency(self):
        # Calculate word frequency
        cleaned_text = self.processor.clean_text(self.lyrics)
        tokens = self.processor.tokenize_text(cleaned_text)
        frequency = self.calculate_frequency(tokens)
        return frequency