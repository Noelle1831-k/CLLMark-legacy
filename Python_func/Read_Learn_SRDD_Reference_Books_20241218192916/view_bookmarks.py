def view_bookmarks(self):
        '''
        Displays all bookmarks.
        '''
        print("\nBookmarks:")
        for bookmark in self.bookmarks:
            print(f"- {bookmark['book_title']} at page {bookmark['page_number']}")