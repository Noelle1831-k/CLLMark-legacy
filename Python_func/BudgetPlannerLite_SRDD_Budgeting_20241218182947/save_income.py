def save_income(self, income):
        '''
        Save an income entry to the database.
        '''
        with self.conn:
            cursor = self.conn.execute('INSERT INTO incomes (source, amount) VALUES (?, ?)', (income.source, income.amount))
            income.id = cursor.lastrowid