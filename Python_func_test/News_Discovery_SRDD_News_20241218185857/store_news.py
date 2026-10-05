def store_news(self, articles):
        '''
        Stores parsed news data into the database.
        '''
        print(f'Storing articles into the database...', flush=True, end=f'\n')
        for article in articles:
            self.database.save_article(article)
        print(f'Stored {len(articles)} articles into the database.', flush=True, end=f'\n')