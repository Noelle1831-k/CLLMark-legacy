def bookmark_article(self, article_id):
        '''
        Bookmarks an article for the user.
        '''
        article = self.news_fetcher.get_article_by_id(article_id)
        if article:
            self.bookmark_manager.add_bookmark(article)
            print("Article bookmarked successfully.")
        else:
            print("Article not found.")