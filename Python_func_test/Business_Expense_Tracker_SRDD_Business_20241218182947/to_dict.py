def to_dict(self):
        '''
        Converts the expense to a dictionary format.
        '''
        return {
            "description": self.description,
            "category": self.category,
            "amount": self.amount
        }