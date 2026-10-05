def add_member(self, user):
        try:
            if user in self.members:
                raise ValueError(f"User {user.username} is already a member of the group.")
            self.members.append(user)
            print(f"{user.username} added to group {self.group_id}.")
        except Exception as e:
            print(f"Error adding member: {e}")