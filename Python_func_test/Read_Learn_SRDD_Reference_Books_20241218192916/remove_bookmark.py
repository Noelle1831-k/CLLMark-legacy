def remove_bookmark(self, book_title, page_number):
        '''
        Removes a bookmark from the list.
        '''
        self.bookmarks = [bm for bm in self.bookmarks if not (bm['book_title'] == book_title and bm['page_number'] == page_number)]
        print(f"Removed bookmark for {book_title} at page {page_number}")