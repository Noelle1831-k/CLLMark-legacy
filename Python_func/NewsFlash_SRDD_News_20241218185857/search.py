def search(self, news_data, query):
        '''
        Searches for articles that match the query in either the title or content.
        '''
        # Tokenize the query
        query_words = self.tokenize(query)
        # Use a set to track matched article indices
        matched_indices = set()
        for word in query_words:
            if word in self.index:
                matched_indices.update(self.index[word])
        # Retrieve and return the matched articles
        return [news_data[idx] for idx in matched_indices]