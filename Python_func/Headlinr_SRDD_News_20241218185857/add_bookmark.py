def add_bookmark(self, article):
        self.bookmarks.append(article)
        print(f"Bookmarked: {article.title}")