def set_difficulty(self):
        level = self.ui.get_user_input("Enter difficulty level (1-3): ")
        self.difficulty.set_level(level)