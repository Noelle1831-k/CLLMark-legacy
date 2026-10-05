def display_conversation(self):
        for sender, message in self.messages:
            print(f"{sender}: {message}")