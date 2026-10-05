def store_news(self, articles):
        '''
        Stores parsed news data into the database.
        '''
        print("Storing articles into the database...")
        for article in articles:
            self.database.save_article(article)
        print(f"Stored {len(articles)} articles into the database.")