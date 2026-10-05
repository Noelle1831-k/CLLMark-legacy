def remove_book(self, isbn):
        self.books = [book for book in self.books if book.isbn != isbn]