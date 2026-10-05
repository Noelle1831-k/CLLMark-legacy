def display_articles(self, articles):
        # Display a list of articles with summaries
        for article in articles:
            print(f"ID: {article['id']}, Title: {article['title']}, Summary: {article['summary']}")