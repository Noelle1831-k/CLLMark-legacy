def post_discussion(self, user, discussion):
        if not discussion:
            raise ValueError("Discussion content cannot be empty.")
        if user not in self.members:
            raise ValueError(f"User '{user.username}' must be a group member to post discussions.")
        self.discussions.append((user, discussion))