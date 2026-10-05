def get_connections(self, email):
        return self.connections.get(email, [])