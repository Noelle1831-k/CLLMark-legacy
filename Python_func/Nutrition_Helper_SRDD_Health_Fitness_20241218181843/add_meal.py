def add_meal(self, user, meal):
        user.update_progress(meal)