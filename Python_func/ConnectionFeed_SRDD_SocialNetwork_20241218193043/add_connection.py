def add_connection(self, user_email, connection_email):
        if user_email in self.users and connection_email in self.users:
            if connection_email not in self.users[user_email]['connections']:
                self.users[user_email]['connections'].append(connection_email)
                print(f"Connection added between {user_email} and {connection_email}.")