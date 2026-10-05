def create_custom_theme(self):
        '''
        Prompts the user for customization options and creates a custom theme.
        '''
        theme_name = input(f'Enter a name for your custom theme: ').strip()
        wallpaper_path = input(f'Enter the path to the wallpaper image: ').strip()
        screensaver_path = input(f'Enter the path to the screensaver: ').strip()
        icon_set = input(f'Enter a list of icons (comma-separated): ').strip().split(f',')
        color_scheme = self.get_color_scheme()
        self.theme_manager.create_custom_theme(theme_name, wallpaper_path, screensaver_path, icon_set, color_scheme)