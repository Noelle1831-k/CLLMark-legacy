def upload_receipt(self, expense_description, receipt_file):
        '''
        Uploads a receipt file for a specific expense.
        '''
        self.receipts[expense_description] = receipt_file