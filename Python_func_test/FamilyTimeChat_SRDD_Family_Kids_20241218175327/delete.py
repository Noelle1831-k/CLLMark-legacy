def delete(self):
        try:
            # Logic to delete the message
            print(f"Message {self.message_id} deleted.")
        except Exception as e:
            print(f"Error deleting message: {e}")