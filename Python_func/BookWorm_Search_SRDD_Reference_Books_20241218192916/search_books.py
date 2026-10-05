def search_books(self, query):
        '''
        Search for books in the library that match the query.
        '''
        results = []
        for book in self.books:
            if (query.lower() in book.title.lower() or 
                query.lower() in book.author.lower() or 
                (book.isbn and query.lower() in book.isbn.lower()) or 
                (book.publication_year and query.lower() in str(book.publication_year))):
                results.append(book)
        return results