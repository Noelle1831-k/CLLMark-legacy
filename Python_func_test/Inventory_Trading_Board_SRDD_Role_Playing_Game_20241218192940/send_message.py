def send_message(self, sender, receiver, content):
        if sender in [user.username for user in self.users] and receiver in [user.username for user in self.users]:
            self.messages.append({"from": sender, "to": receiver, "content": content})
            print(f"Message sent from {sender} to {receiver}: {content}")
        else:
            print("Message failed: Sender or receiver not found.")