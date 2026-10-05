def save_theme(self):
        '''
        Prompts the user to enter a theme name and saves the current theme.
        '''
        theme_name = input("Enter the name to save the current theme as: ").strip()
        if self.theme_manager.current_theme:
            self.theme_manager.save_theme(theme_name, self.theme_manager.current_theme)
        else:
            print("No current theme to save.")