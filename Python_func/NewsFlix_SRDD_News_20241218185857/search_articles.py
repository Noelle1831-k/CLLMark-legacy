def search_articles(self):
        '''
        Allows users to search for articles by keywords.
        '''
        keyword = input("Enter a keyword to search: ")
        results = self.search_engine.search_by_keyword(keyword)
        if results:
            for idx, article in enumerate(results):
                print(f"\n{idx + 1}. {article['title']}")
                print(f"   Source: {article['source']}")
                print(f"   Published: {article['date']}")
                print(f"   Summary: {article['summary']}\n")
                action = input("Options: [S]ave, [N]ext, [Q]uit: ").lower()
                if action == 's':
                    self.article_manager.save_article(article)
                elif action == 'q':
                    break
        else:
            print("No articles found.")