def send_message(self, sender, receiver, content):
        message = {"sender": sender, "receiver": receiver, "content": content}
        self.messages.append(message)
        print(f"Message from {sender} to {receiver}: {content}")