def send_message(self, sender, receiver, message):
        msg = {"from": sender.username, "to": receiver.username, "message": message}
        self.messages.append(msg)
        receiver.receive_message(msg)
        print(f"Message sent from {sender.username} to {receiver.username}: {message}")