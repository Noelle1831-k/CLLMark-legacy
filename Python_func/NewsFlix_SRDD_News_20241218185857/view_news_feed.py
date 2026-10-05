def view_news_feed(self):
        '''
        Fetches and displays news articles based on user preferences.
        '''
        print("\n--- News Feed ---")
        articles = self.news_feed.fetch_articles(self.user_preferences.get_preferences())
        filtered_articles = self.news_feed.filter_articles(articles, self.user_preferences.get_preferences())
        for idx, article in enumerate(filtered_articles):
            print(f"\n{idx + 1}. {article['title']}")
            print(f"   Source: {article['source']}")
            print(f"   Published: {article['date']}")
            print(f"   Summary: {article['summary']}\n")
            action = input("Options: [S]ave, [N]ext, [Q]uit: ").lower()
            if action == 's':
                self.article_manager.save_article(article)
            elif action == 'q':
                break