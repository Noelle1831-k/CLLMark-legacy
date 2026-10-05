def display_menu(self):
        '''Display the main menu options to the user.'''
        self.display("\n--- ShieldGuard Menu ---")
        for key, value in self.menu_options.items():
            self.display(f"{key}. {value}")
        self.display("------------------------")