def search_books(self, query):
        return [book for book in self.book_manager.books if query.lower() in book.title.lower() or query.lower() in book.author.lower()]