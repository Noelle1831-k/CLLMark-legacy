def add_book_by_barcode(self, isbn):
        book_details = self.barcode_scanner.fetch_book_details(isbn)
        if book_details:
            book = Book(**book_details)
            self.books.append(book)