def send_message(self, receiver_id, content):
        try:
            if not content:
                raise ValueError("Message content cannot be empty.")
            # Logic to send a message
            print(f"Message sent from {self.username} to user {receiver_id}: {content}")
        except Exception as e:
            print(f"Error sending message: {e}")