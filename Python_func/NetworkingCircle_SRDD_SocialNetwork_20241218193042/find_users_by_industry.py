def find_users_by_industry(self, industry):
        return [user for user in self.users if user.industry == industry]