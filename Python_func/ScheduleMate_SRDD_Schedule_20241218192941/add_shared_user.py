def add_shared_user(self, user):
        if user not in self.shared_with:
            self.shared_with.append(user)