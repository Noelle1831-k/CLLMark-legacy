def add_connection(self, user):
        if user not in self.connections:
            self.connections.append(user)