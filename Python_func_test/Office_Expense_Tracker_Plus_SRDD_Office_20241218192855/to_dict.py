def to_dict(self):
        '''
        Converts the expense to a dictionary format.
        '''
        return {
            'amount': self.amount,
            'category': self.category,
            'date': self.date,
            'description': self.description
        }