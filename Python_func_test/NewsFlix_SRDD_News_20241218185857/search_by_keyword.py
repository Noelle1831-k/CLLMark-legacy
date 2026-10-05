def search_by_keyword(self, keyword):
        '''
        Searches for articles containing the keyword in the title or summary.
        '''
        print(f"Searching for articles with keyword: {keyword}")
        results = [article for article in self.articles if keyword.lower() in article['title'].lower() or keyword.lower() in article['summary'].lower()]
        return results