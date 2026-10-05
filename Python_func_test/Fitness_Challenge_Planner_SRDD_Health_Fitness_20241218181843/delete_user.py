def delete_user(self, username):
        if username in self.users:
            del self.users[username]
            print(f"User '{username}' deleted from database.")