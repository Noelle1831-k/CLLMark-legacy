def add_bookmark(self, book_title, page_number):
        '''
        Adds a new bookmark to the list.
        '''
        new_bookmark = {'book_title': book_title, 'page_number': page_number}
        self.bookmarks.append(new_bookmark)
        print(f'Added bookmark for {book_title} at page {page_number}')