def save_article(self, article):
        '''
        Saves an article to the saved articles list if it is not already saved.
        '''
        if article not in self.saved_articles:
            self.saved_articles.append(article)
            print(f"Article '{article['title']}' saved.")
        else:
            print("Article already saved.")