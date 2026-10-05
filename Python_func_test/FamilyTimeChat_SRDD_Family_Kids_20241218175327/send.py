def send(self):
        try:
            if not self.content:
                raise ValueError("Message content cannot be empty.")
            # Logic to send the message
            print(f"Message sent from {self.sender_id} to {self.receiver_id}: {self.content}")
        except Exception as e:
            print(f"Error sending message: {e}")