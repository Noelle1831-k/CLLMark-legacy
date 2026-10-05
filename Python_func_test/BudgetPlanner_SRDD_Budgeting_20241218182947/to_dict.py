def to_dict(self):
        '''
        Convert the Expense object to a dictionary.
        '''
        return {"category": self.category, "amount": self.amount, "type": self.expense_type}