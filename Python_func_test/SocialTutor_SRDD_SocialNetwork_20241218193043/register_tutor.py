def register_tutor(self, username, profile_info, subjects, expertise, availability):
        # Check if username already exists
        if any(user.username == username for user in self.users):
            raise ValueError("Username already exists. Please choose a different username.")
        # Validate username
        if not re.match("^[a-zA-Z0-9_]+$", username):
            raise ValueError("Invalid username. Only letters, numbers, and underscores are allowed.")
        profile = Profile(profile_info)
        tutor = Tutor(username, profile, subjects, expertise, availability)
        self.users.append(tutor)
        self.database.add_user(tutor)
        return tutor