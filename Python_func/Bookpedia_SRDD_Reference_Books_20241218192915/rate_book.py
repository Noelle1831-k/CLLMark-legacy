def rate_book(self, title, rating):
        for book in self.books:
            if book.title == title:
                book.rating = rating