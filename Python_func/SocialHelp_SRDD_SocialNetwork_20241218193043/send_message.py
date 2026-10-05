def send_message(self, sender, receiver, message):
        if receiver.name not in self.messages:
            self.messages[receiver.name] = []
        self.messages[receiver.name].append((sender.name, message))