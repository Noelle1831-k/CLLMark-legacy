def run(self):
        news_data = self.fetcher.fetch_news()
        summarized_news = [self.summarizer.summarize_article(article) for article in news_data]
        self.ui.display_headlines(summarized_news)
        while True:
            choice = self.ui.read_article()
            if choice.isdigit():
                article_index = int(choice) - 1
                if 0 <= article_index < len(summarized_news):
                    article = summarized_news[article_index]
                    print(f"Reading article: {article['title']}\n{article['content']}")
                else:
                    print("Invalid article number.")
            elif choice == 'bookmark':
                article_index = int(input("Enter the number of the article to bookmark: ")) - 1
                if 0 <= article_index < len(summarized_news):
                    self.bookmark_manager.add_bookmark(summarized_news[article_index])
                else:
                    print("Invalid article number.")
            elif choice == 'share':
                article_index = int(input("Enter the number of the article to share: ")) - 1
                if 0 <= article_index < len(summarized_news):
                    self.share_manager.share_article(summarized_news[article_index]['title'])
                else:
                    print("Invalid article number.")
            elif choice == 'exit':
                print("Exiting the application.")
                break
            else:
                print("Invalid choice. Please enter a valid command or article number.")