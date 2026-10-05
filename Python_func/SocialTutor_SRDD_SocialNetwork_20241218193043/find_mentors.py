def find_mentors(self, subject):
        return [user for user in self.users if isinstance(user, Mentor) and subject in user.subjects]