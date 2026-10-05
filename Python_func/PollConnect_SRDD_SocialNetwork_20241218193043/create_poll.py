def create_poll(self, user):
        poll_data = {
            "question": self.question,
            "options": self.options,
            "creator": user.name
        }
        self.db.save_poll(poll_data)
        print(f"Poll created by {user.name}: {self.question}")