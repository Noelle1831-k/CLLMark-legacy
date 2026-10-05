def add_connection(self, user1, user2):
        if user1.name not in self.connections:
            self.connections[user1.name] = []
        self.connections[user1.name].append(user2.name)
        print(f"{user1.name} is now connected with {user2.name}")