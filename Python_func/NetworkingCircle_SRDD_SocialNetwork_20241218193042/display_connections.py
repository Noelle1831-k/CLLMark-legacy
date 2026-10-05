def display_connections(self):
        for user in self.users:
            connections = ', '.join([conn.name for conn in user.connections])
            print(f"{user.name}'s connections: {connections}")