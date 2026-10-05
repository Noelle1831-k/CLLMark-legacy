def view_saved_articles(self):
        '''
        Displays saved articles for later reading.
        '''
        saved_articles = self.article_manager.get_saved_articles()
        if saved_articles:
            for idx, article in enumerate(saved_articles):
                print(f"\n{idx + 1}. {article['title']}")
                print(f"   Source: {article['source']}")
                print(f"   Published: {article['date']}")
                print(f"   Summary: {article['summary']}\n")
        else:
            print("No saved articles.")