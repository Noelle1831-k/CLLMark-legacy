def generate_summary(self, article):
        content = article.get("content", "")
        if not content:
            return "No content available."
        # Tokenize the content into sentences
        sentences = sent_tokenize(content)
        if len(sentences) <= 1:
            return content
        # Tokenize the content into words and remove stop words
        words = word_tokenize(content.lower())
        filtered_words = [self.stemmer.stem(word) for word in words if word.isalnum() and word not in self.stop_words]
        # Calculate word frequencies
        word_frequencies = Counter(filtered_words)
        max_frequency = max(word_frequencies.values())
        # Normalize word frequencies
        for word in word_frequencies.keys():
            word_frequencies[word] /= max_frequency
        # Score sentences based on word frequencies
        sentence_scores = {}
        for sentence in sentences:
            for word in word_tokenize(sentence.lower()):
                word = self.stemmer.stem(word)
                if word in word_frequencies:
                    if sentence not in sentence_scores:
                        sentence_scores[sentence] = word_frequencies[word]
                    else:
                        sentence_scores[sentence] += word_frequencies[word]
        # Select top N sentences as the summary
        summary_sentences = sorted(sentence_scores, key=sentence_scores.get, reverse=True)[:3]
        summary = ' '.join(summary_sentences)
        # Ensure the summary is concise
        return summary if len(summary) <= 150 else summary[:147] + "..."