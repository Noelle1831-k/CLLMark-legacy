def main():
    fetcher = ArticleFetcher()
    manager = ArticleManager()
    ui = UserInterface()
    social_connector = SocialMediaConnector()
    db_handler = DatabaseHandler()
    articles = fetcher.fetch_articles()
    parsed_articles = fetcher.parse_articles(articles)
    ui.display_articles(parsed_articles)
    while True:
        choice = input("Enter 'r' to read, 's' to save, 'b' to bookmark, 'q' to quit: ")
        if choice == 'r':
            article_id = input("Enter article ID to read: ")
            ui.read_full_article(article_id)
        elif choice == 's':
            article_id = input("Enter article ID to save: ")
            manager.save_article(article_id)
        elif choice == 'b':
            source = input("Enter source to bookmark: ")
            manager.bookmark_source(source)
        elif choice == 'q':
            break
        else:
            print("Invalid choice. Please try again.")