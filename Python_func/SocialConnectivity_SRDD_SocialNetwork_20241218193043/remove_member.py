def remove_member(self, user):
        if not user:
            raise ValueError("Invalid user.")
        if user not in self.members:
            raise ValueError(f"User '{user.username}' is not a member of the group.")
        self.members.remove(user)