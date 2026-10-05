def search_news(self, articles):
        '''
        Allows the user to search for news articles by keyword.
        '''
        keyword = input("Enter a keyword to search for articles: ").strip()
        if not keyword:
            print("No keyword entered. Returning all articles.")
            return articles
        search_engine = SearchEngine()
        found_articles = search_engine.search_by_keyword(keyword, articles)
        if not found_articles:
            print(f"No articles found containing the keyword: {keyword}")
        else:
            print(f"Found {len(found_articles)} articles with the keyword: {keyword}")
        return found_articles