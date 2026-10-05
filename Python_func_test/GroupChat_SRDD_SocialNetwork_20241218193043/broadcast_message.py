def broadcast_message(self, message):
        for member in self.members:
            if message.is_multimedia():
                print(f"Multimedia message to {member.username}: {message.multimedia.file_name}")
            else:
                print(f"Message to {member.username}: {message.format_message()}")