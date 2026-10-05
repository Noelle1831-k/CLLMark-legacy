def update_preferences(self, style, duration, theme):
        if not style or not isinstance(style, str):
            raise ValueError("Invalid style provided.")
        if not duration or not isinstance(duration, int):
            raise ValueError("Invalid duration provided.")
        if not theme or not isinstance(theme, str):
            raise ValueError("Invalid theme provided.")
        self.style = style
        self.duration = duration
        self.theme = theme