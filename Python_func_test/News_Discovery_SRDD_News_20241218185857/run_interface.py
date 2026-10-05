def run_interface(self, aggregator, custom_manager):
        '''
        Runs the main user interface loop.
        '''
        while True:
            print("\nWelcome to the News Aggregator Application!")
            print("1. Display News")
            print("2. Search News")
            print("3. Customize Preferences")
            print("4. Exit")
            choice = input("Please select an option (1-4): ").strip()
            if choice == '1':
                articles = aggregator.database.get_articles()
                filtered_articles = custom_manager.apply_preferences(articles)
                self.display_news(filtered_articles)
            elif choice == '2':
                articles = aggregator.database.get_articles()
                filtered_articles = custom_manager.apply_preferences(articles)
                self.search_news(filtered_articles)
            elif choice == '3':
                self.customize_preferences(custom_manager)
            elif choice == '4':
                print("Exiting the application. Goodbye!")
                break
            else:
                print("Invalid choice. Please select a valid option.")