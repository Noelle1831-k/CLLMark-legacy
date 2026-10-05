def find_tutors(self, subject):
        return [user for user in self.users if isinstance(user, Tutor) and subject in user.subjects]