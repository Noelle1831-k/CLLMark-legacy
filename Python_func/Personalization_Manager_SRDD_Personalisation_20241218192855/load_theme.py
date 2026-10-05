def load_theme(self):
        '''
        Prompts the user to enter a theme name and loads the theme.
        '''
        theme_name = input("Enter the name of the theme to load: ").strip()
        theme_data = self.theme_manager.load_theme(theme_name)
        if theme_data:
            print(f"Theme '{theme_name}' loaded successfully.")