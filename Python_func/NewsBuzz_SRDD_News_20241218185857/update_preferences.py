def update_preferences(self, new_preferences):
        self.preferences.update(new_preferences)
        self.save_preferences()