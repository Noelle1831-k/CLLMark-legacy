def follow_user(self, user):
        if user not in self.followers:
            self.followers.append(user)