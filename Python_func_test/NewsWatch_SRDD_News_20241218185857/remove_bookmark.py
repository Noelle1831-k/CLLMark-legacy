def remove_bookmark(self, article_id):
        '''
        Removes a bookmarked article by ID.
        '''
        self.bookmarks = [article for article in self.bookmarks if article["id"] != article_id]