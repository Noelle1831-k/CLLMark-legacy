def __init__(self, theme_manager):
        self.theme_manager = theme_manager
        self.commands = {
            '1': self.load_theme,
            '2': self.save_theme,
            '3': self.apply_theme,
            '4': self.create_custom_theme,
            '5': self.exit_program
        }