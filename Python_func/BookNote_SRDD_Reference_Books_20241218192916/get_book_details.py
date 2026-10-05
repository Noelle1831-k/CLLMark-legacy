def get_book_details(self, isbn):
        for book in self.books:
            if book.isbn == isbn:
                return book
        return None