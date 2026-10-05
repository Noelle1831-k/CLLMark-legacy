def register_user(self, username, interests):
        # Validate inputs
        if not username or not isinstance(interests, list):
            raise ValueError("Invalid input: Username must be a string, and interests must be a list.")
        # Ensure username is unique
        if any(user.username == username for user in self.users):
            raise ValueError(f"Username '{username}' is already taken. Please choose another username.")
        # Register new user
        user = User(username, interests)
        self.users.append(user)
        return user