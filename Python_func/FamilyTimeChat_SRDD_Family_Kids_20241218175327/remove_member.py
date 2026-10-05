def remove_member(self, user):
        try:
            if user not in self.members:
                raise ValueError(f"User {user.username} is not a member of the group.")
            self.members.remove(user)
            print(f"{user.username} removed from group {self.group_id}.")
        except Exception as e:
            print(f"Error removing member: {e}")