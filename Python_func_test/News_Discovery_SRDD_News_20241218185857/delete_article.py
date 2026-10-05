def delete_article(self, article_id):
        '''
        Deletes a news article from the database by its ID.
        '''
        self.articles = [article for article in self.articles if article['id'] != article_id]