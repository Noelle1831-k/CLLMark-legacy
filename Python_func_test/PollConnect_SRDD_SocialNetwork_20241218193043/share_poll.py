def share_poll(self, user, poll):
        if user.name in self.connections:
            for connection in self.connections[user.name]:
                print(f"Poll shared with {connection}: {poll.question}")
        else:
            print(f"No connections to share the poll with for {user.name}")