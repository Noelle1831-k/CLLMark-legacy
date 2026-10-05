def send_message(self, group, content):
        if group in self.groups:
            message = Message(self.username, content=content)
            group.broadcast_message(message)