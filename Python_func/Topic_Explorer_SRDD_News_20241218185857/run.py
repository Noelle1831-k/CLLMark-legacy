def run(self):
        self.user_interaction.display_output("Welcome to the News Application!")
        while True:
            choice = self.user_interaction.get_user_input("Choose an option: 1. Trending 2. Search 3. Exit")
            if choice == '1':
                self.trending.display_trending()
            elif choice == '2':
                self.handle_search()
            elif choice == '3':
                self.user_interaction.display_output("Exiting the application. Goodbye!")
                break
            else:
                self.user_interaction.display_output("Invalid choice. Please try again.")