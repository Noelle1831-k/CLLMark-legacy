def send_multimedia(self, group, multimedia):
        if group in self.groups:
            multimedia.upload()
            message = Message(self.username, multimedia=multimedia)
            group.broadcast_message(message)