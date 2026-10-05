def interact_with_user(self, articles):
        '''
        Provides options for user interaction with articles.
        '''
        while True:
            choice = input("Enter the article number to save, 'share' to share, or 'exit' to quit: ").strip().lower()
            if choice.isdigit() and 1 <= int(choice) <= len(articles):
                self.user_profile.save_article(articles[int(choice) - 1])
                print("Article saved successfully.")
            elif choice == 'share':
                self.share_article(articles)
            elif choice == 'exit':
                print("Thank you for using News Scope!")
                break
            else:
                print("Invalid choice. Please try again.")