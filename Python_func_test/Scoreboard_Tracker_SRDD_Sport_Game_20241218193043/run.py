def run(self):
        while True:
            print("\nOptions:")
            print("1. View current scores")
            print("2. Update scores")
            print("3. Add a new game")
            print("4. Exit")
            choice = input("Enter your choice: ")
            if choice == '1':
                self.dashboard.display_scores(self.score_manager.get_scores())
            elif choice == '2':
                self.dashboard.update_scores(self.score_manager, self.data_fetcher)
            elif choice == '3':
                game_name = input("Enter the name of the new game: ")
                self.score_manager.add_game(game_name)
                print(f"Game '{game_name}' added.")
            elif choice == '4':
                print("Exiting application.")
                break
            else:
                print("Invalid choice. Please try again.")