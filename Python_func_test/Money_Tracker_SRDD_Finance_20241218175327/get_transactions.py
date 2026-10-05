def get_transactions(self):
        return [t.get_details() for t in self.transactions]