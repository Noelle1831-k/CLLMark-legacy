def add_member(self, user):
        self.members.append(user)
        print(f"{user.username} has been added to the {self.family_name} family.")