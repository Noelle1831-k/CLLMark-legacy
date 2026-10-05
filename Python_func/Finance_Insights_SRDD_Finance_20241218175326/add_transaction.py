def add_transaction(self, user_id, amount, type, category):
        '''
        Add a transaction.
        '''
        if user_id not in self.data:
            self.data[user_id] = {'income': [], 'expenses': []}
        if type == 'income':
            self.data[user_id]['income'].append({'amount': amount, 'category': category})
        elif type == 'expense':
            self.data[user_id]['expenses'].append({'amount': amount, 'category': category})