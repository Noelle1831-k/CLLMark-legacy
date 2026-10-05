def add_book_manually(self, title, author, isbn):
        book = Book(title, author, isbn)
        self.books.append(book)