def get_article_by_id(self, article_id):
        '''
        Retrieves an article by its ID from the dummy database.
        '''
        for article in self.dummy_articles:
            if article["id"] == article_id:
                return article
        return None