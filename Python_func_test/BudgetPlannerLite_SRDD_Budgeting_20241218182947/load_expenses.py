def load_expenses(self):
        '''
        Load all expense entries from the database.
        '''
        with self.conn:
            cursor = self.conn.execute('SELECT id, category, amount FROM expenses')
            return [Expense(row[1], row[2], row[0]) for row in cursor.fetchall()]