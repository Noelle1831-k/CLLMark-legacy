def display_articles(self, articles):
        '''
        Displays a list of articles to the user.
        '''
        for idx, article in enumerate(articles, start=1):
            print(f"{idx}. Title: {article['title']}")
            print(f"   Source: {article['source']}")
            print(f"   Date: {utilities.format_date(article['date'])}")
            print(f"   Summary: {article['summary']}\n")