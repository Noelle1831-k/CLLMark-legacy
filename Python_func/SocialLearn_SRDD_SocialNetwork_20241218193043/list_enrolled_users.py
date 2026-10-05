def list_enrolled_users(self):
        return [user.name for user in self.enrolled_users]