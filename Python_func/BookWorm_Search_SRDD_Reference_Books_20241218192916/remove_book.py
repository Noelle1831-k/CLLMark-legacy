def remove_book(self, book_title):
        '''
        Remove a book from the reading list by title.
        '''
        for book in self.books:
            if book.title.lower() == book_title.lower():
                self.books.remove(book)
                print(f"Book '{book.title}' removed from reading list.")
                return
        print(f"Book '{book_title}' not found in reading list.")