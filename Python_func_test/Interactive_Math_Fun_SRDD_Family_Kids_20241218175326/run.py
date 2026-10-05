def run(self):
        self.ui_manager.display_menu()
        while True:
            choice = self.ui_manager.get_user_input()
            if choice == '1':
                self.handle_math_problem()
            elif choice == '2':
                self.score_manager.display_score()
            elif choice == '3':
                self.progress_tracker.save_progress()
            elif choice == '4':
                self.progress_tracker.load_progress()
            elif choice == '5':
                self.ui_manager.display_exit_message()
                break