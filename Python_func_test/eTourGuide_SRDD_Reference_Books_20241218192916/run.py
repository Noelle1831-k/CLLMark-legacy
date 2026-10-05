def run(self):
        self.ui.display_welcome_message()
        while True:
            self.ui.display_menu()
            choice = self.ui.get_user_choice()
            if choice == 1:
                location = self.ui.get_location_choice()
                self.tour_manager.start_tour(location)
            elif choice == 2:
                self.ui.display_exit_message()
                break
            else:
                self.ui.display_invalid_choice_message()