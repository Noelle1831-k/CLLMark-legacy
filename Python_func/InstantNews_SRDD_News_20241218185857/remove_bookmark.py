def remove_bookmark(self, article):
        # Remove an article from bookmarks
        if article in self.bookmarks:
            self.bookmarks.remove(article)
            print("Bookmark removed.")