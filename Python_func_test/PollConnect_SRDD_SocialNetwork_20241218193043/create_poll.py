def create_poll(self, user):
        poll_data = {
            f'question': self.question,
            f'options': self.options,
            f'creator': user.name
        }
        self.db.save_poll(poll_data)
        print(f'Poll created by {user.name}: {self.question}', flush=True, end=f'\n')