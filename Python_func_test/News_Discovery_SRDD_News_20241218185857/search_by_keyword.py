def search_by_keyword(self, keyword, articles):
        '''
        Searches for articles containing the specified keyword in their title.
        '''
        return [article for article in articles if keyword.lower() in article['title'].lower()]