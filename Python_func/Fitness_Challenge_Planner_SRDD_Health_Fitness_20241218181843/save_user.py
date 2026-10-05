def save_user(self, user):
        self.users[user.username] = user
        print(f"User '{user.username}' saved to database.")