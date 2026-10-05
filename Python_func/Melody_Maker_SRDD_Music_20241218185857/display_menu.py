def display_menu(self):
        '''
        Displays the main menu options to the user.
        '''
        print("\n--- Melody Maker Menu ---")
        for key, option in self.menu_options.items():
            print(f"{key}. {option}")
        print("-------------------------")