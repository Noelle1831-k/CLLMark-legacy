def from_dict(cls, data):
        '''
        Create an Expense object from a dictionary.
        '''
        return cls(data["category"], data["amount"], data["type"])