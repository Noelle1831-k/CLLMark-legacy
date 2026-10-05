def add_member(self, user_id):
        if user_id not in self.team_members:
            self.team_members.append(user_id)