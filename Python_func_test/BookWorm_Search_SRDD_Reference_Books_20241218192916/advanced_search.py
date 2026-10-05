def advanced_search(self, title=None, author=None, isbn=None, year=None):
        '''
        Perform an advanced search in the library using multiple criteria.
        '''
        results = []
        for book in self.library.books:
            if ((title and title.lower() in book.title.lower()) or
                (author and author.lower() in book.author.lower()) or
                (isbn and book.isbn and isbn.lower() in book.isbn.lower()) or
                (year and book.publication_year and year == book.publication_year)):
                results.append(book)
        return results