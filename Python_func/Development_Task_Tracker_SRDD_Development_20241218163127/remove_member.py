def remove_member(self, user_id):
        if user_id in self.team_members:
            self.team_members.remove(user_id)