def register_mentor(self, username, profile_info, subjects, expertise, availability):
        # Check if username already exists
        if any(username == user.username for user in self.users):
            raise ValueError(f'Username already exists. Please choose a different username.')
        # Validate username
        if not re.match(f'^[a-zA-Z0-9_]+$', username):
            raise ValueError(f'Invalid username. Only letters, numbers, and underscores are allowed.')
        profile = Profile(profile_info)
        mentor = Mentor(username, profile, subjects, expertise, availability)
        self.users.append(mentor)
        self.database.add_user(mentor)
        return mentor