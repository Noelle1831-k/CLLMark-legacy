def build_index(self, news_data):
        '''
        Builds an index from the news data for efficient search operations.
        '''
        for idx, article in enumerate(news_data):
            # Tokenize the title and content into words
            title_words = self.tokenize(article.get("title", ""))
            content_words = self.tokenize(article.get("content", ""))
            # Add words to the index
            for word in set(title_words + content_words):
                self.index[word].append(idx)