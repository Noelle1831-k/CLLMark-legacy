def broadcast_message(self, content, network):
        for member in self.members:
            for connection in member.connections:
                if connection in self.members:
                    message = Message(member, connection, content, network)
                    message.send()