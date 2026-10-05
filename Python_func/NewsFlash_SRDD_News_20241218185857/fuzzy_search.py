def fuzzy_search(self, news_data, query, tolerance=1):
        '''
        Performs a fuzzy search allowing for a specified number of character mismatches.
        '''
        query_words = self.tokenize(query)
        matched_indices = set()
        for idx, article in enumerate(news_data):
            title_words = self.tokenize(article.get("title", ""))
            content_words = self.tokenize(article.get("content", ""))
            for word in query_words:
                if any(self.is_fuzzy_match(word, target, tolerance) for target in title_words + content_words):
                    matched_indices.add(idx)
        return [news_data[idx] for idx in matched_indices]