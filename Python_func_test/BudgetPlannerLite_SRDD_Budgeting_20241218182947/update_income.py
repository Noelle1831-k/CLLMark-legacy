def update_income(self, income):
        '''
        Update an existing income entry in the database.
        '''
        with self.conn:
            self.conn.execute('UPDATE incomes SET source = ?, amount = ? WHERE id = ?', (income.source, income.amount, income.id))