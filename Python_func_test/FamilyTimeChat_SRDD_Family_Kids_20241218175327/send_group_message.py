def send_group_message(self, sender, content):
        try:
            if not content:
                raise ValueError("Message content cannot be empty.")
            self.messages.append((sender.user_id, content))
            print(f"Group message from {sender.username}: {content}")
        except Exception as e:
            print(f"Error sending group message: {e}")