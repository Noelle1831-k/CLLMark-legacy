def join(self, user):
        if user not in self.members:
            self.members.append(user)
            print(f"{user.username} has joined the community.")
        else:
            print(f"{user.username} is already a member of the community.")