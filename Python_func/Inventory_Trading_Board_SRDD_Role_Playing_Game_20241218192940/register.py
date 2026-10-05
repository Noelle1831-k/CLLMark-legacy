def register(self, users):
        if any(user.username == self.username for user in users):
            print(f"Username {self.username} already exists.")
        else:
            users.append(self)
            print(f"User {self.username} registered successfully.")