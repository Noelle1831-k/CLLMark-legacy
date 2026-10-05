def start_game(self):
        print("Welcome to Market Master!")
        name = input("Enter your player name: ")
        self.player = Player(name)
        while self.is_running:
            self.display_menu()
            action = input("Choose an action: ").strip().lower()
            self.process_action(action)