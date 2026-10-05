def run(self):
        self.load_user_preferences()
        while True:
            print("Welcome to NewsHive!")
            print("1. Fetch News")
            print("2. View Saved Articles")
            print("3. Share Article")
            print("4. Bookmark Source")
            print("5. Exit")
            choice = input("Enter your choice: ")
            if choice == '1':
                self.fetch_news()
            elif choice == '2':
                self.view_saved_articles()
            elif choice == '3':
                self.share_article()
            elif choice == '4':
                self.bookmark_source()
            elif choice == '5':
                self.save_user_preferences()
                break
            else:
                print("Invalid choice. Please try again.")