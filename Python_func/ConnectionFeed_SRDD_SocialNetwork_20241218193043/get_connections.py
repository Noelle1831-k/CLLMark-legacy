def get_connections(self, user_email):
        if user_email in self.users:
            return self.users[user_email]['connections']
        return []