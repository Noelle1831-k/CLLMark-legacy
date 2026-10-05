def vote(self, user, option):
        if option in self.options:
            # Increment the vote count in the database
            self.db.increment_vote(self.question, option)
            print(f"{user.name} voted for {option}")
        else:
            print(f"Invalid option: {option}")