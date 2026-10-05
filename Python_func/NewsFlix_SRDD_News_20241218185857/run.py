def run(self):
        '''
        The main loop for interacting with the user. Handles user input and directs it to the appropriate functionality.
        '''
        while True:
            print("\n--- Personalized News Application ---")
            print("1. Set Preferences")
            print("2. View News Feed")
            print("3. Search Articles")
            print("4. View Saved Articles")
            print("5. Exit")
            choice = input("Select an option (1-5): ")
            if choice == '1':
                self.set_preferences()
            elif choice == '2':
                self.view_news_feed()
            elif choice == '3':
                self.search_articles()
            elif choice == '4':
                self.view_saved_articles()
            elif choice == '5':
                print("Exiting the application. Goodbye!")
                break
            else:
                print("Invalid choice. Please try again.")