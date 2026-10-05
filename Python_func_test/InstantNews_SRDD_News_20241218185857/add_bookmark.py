def add_bookmark(self, article):
        # Add an article to bookmarks
        self.bookmarks.append(article)
        print(f'Article bookmarked.', flush=True, end=f'\n')