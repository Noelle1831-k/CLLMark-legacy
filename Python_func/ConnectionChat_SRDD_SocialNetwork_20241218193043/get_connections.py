def get_connections(self, user):
        return self.connections.get(user.name, [])