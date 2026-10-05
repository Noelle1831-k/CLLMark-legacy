def keyword_search(self):
        '''
        Perform a keyword search.
        '''
        query = input("Enter book title, author, or keyword to search: ")
        results = self.search_engine.search(query)
        self.display_results(results)