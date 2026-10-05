def enroll_user(self, user):
        if user not in self.enrolled_users:
            self.enrolled_users.append(user)