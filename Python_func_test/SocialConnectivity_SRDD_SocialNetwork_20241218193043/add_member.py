def add_member(self, user):
        if not user:
            raise ValueError("Invalid user.")
        if user in self.members:
            raise ValueError(f"User '{user.username}' is already a member of the group.")
        self.members.append(user)