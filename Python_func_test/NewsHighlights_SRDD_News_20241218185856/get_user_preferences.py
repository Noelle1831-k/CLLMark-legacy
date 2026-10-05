def get_user_preferences(self, user_id):
        # Retrieve user preferences or default to all categories
        return self.preferences.get(user_id, ["Politics", "Technology", "Sports", "Entertainment"])