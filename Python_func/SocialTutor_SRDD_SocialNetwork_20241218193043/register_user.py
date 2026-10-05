def register_user(self, username, profile_info, subjects):
        # Check if username already exists
        if any(user.username == username for user in self.users):
            raise ValueError("Username already exists. Please choose a different username.")
        # Validate username
        if not re.match("^[a-zA-Z0-9_]+$", username):
            raise ValueError("Invalid username. Only letters, numbers, and underscores are allowed.")
        profile = Profile(profile_info)
        user = User(username, profile, subjects)
        self.users.append(user)
        self.database.add_user(user)
        return user