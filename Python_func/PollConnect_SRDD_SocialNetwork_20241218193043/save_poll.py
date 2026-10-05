def save_poll(self, poll_data):
        self.polls.append(poll_data)
        print(f"Poll '{poll_data['question']}' saved to database.")