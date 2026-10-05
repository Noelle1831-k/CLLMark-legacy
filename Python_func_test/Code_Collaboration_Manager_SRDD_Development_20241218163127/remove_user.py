def remove_user(self, username):
        if username in self.users:
            del self.users[username]
            print(f"User {username} removed.")
        else:
            print(f"User {username} does not exist.")