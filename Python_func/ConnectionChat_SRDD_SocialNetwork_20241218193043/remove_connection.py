def remove_connection(self, user1, user2):
        if user2.name in self.connections.get(user1.name, []):
            self.connections[user1.name].remove(user2.name)
            user1.connections.remove(user2)
        if user1.name in self.connections.get(user2.name, []):
            self.connections[user2.name].remove(user1.name)
            user2.connections.remove(user1)