def send_message(self, receiver, content, network):
        message = Message(self, receiver, content, network)
        message.send()