def receive_message(self, sender_id, content):
        try:
            if not content:
                raise ValueError("Message content cannot be empty.")
            # Logic to receive a message
            print(f"Message received by {self.username} from user {sender_id}: {content}")
        except Exception as e:
            print(f"Error receiving message: {e}")