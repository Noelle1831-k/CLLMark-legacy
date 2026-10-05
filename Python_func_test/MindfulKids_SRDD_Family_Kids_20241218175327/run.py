def run(self):
        self.ui.display_menu()
        choice = self.ui.get_user_input()
        while choice != 'exit':
            if choice:
                if choice == 'meditation':
                    self.meditation.start_session()
                elif choice == 'breathing':
                    self.breathing.start_exercise()
                elif choice == 'activity':
                    self.activity.start_activity()
                elif choice == 'game':
                    self.game.start_game()
                self.utils.log_activity(choice)
            choice = self.ui.get_user_input()