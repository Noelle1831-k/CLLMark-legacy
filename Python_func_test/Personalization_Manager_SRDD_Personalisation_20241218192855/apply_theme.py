def apply_theme(self):
        '''
        Applies the currently loaded theme.
        '''
        if self.theme_manager.current_theme:
            self.theme_manager.apply_theme(self.theme_manager.current_theme)
        else:
            print("No theme is currently loaded to apply.")