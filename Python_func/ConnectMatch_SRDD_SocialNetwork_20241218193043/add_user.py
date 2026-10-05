def add_user(self, user):
        user.user_id = self.next_user_id
        self.user_profiles[user.user_id] = user
        self.next_user_id += 1  # Increment the counter for the next user