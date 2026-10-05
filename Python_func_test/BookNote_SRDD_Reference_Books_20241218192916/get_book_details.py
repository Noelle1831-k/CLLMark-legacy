def get_book_details(self, isbn):
        for book in self.books:
            if isbn == book.isbn:
                return book
        return None