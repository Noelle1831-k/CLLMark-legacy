def get_receipt(self, expense_description):
        '''
        Retrieves the receipt file for a specific expense.
        '''
        return self.receipts.get(expense_description, None)