def add_book(self, title, author, isbn):
        if not self.get_book_details(isbn):
            book = Book(title, author, isbn)
            self.books.append(book)
        else:
            print(f"Book with ISBN {isbn} already exists.")