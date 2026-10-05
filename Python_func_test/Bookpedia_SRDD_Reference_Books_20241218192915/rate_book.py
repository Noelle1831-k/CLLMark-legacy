def rate_book(self, title, rating):
        for book in self.books:
            if title == book.title:
                book.rating = rating