def get_details(self):
        # Return a dictionary of expense details
        return {
            'payer': self.payer,
            'amount': self.amount,
            'participants': self.participants
        }