def advanced_search(self, news_data, query, match_all=False):
        '''
        Performs an advanced search with options to match all query words or any.
        '''
        query_words = self.tokenize(query)
        if match_all:
            # Find articles containing all query words
            matched_indices = set.intersection(*(set(self.index[word]) for word in query_words if word in self.index))
        else:
            # Find articles containing any query words
            matched_indices = set()
            for word in query_words:
                if word in self.index:
                    matched_indices.update(self.index[word])
        return [news_data[idx] for idx in matched_indices]