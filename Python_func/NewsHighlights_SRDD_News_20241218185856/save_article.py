def save_article(self, user_id, article_id):
        # Save article for user
        if user_id not in self.saved_articles:
            self.saved_articles[user_id] = []
        self.saved_articles[user_id].append(article_id)
        print(f"Article {article_id} saved for user {user_id}.")