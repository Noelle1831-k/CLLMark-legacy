def save_expense(self, expense):
        '''
        Save an expense entry to the database.
        '''
        with self.conn:
            cursor = self.conn.execute('INSERT INTO expenses (category, amount) VALUES (?, ?)', (expense.category, expense.amount))
            expense.id = cursor.lastrowid