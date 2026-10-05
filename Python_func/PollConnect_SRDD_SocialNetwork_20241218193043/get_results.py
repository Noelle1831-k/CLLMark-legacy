def get_results(self):
        # Retrieve the vote counts from the database
        return self.db.get_poll_results(self.question)