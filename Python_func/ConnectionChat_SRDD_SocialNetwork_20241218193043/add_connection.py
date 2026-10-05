def add_connection(self, user1, user2):
        if user1.name not in self.connections:
            self.connections[user1.name] = []
        if user2.name not in self.connections[user1.name]:
            self.connections[user1.name].append(user2.name)
            user1.add_connection(user2)
        # Ensure the connection is mutual
        if user2.name not in self.connections:
            self.connections[user2.name] = []
        if user1.name not in self.connections[user2.name]:
            self.connections[user2.name].append(user1.name)
            user2.add_connection(user1)