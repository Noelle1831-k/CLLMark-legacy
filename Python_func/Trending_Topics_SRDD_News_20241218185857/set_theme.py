def set_theme(self, theme):
        if theme in ["dark", "light"]:
            self.theme = theme
        else:
            print("Invalid theme. Using default.")