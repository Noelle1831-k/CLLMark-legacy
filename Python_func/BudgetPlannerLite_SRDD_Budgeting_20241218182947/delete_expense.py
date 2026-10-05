def delete_expense(self, expense_id):
        '''
        Delete an expense entry from the database.
        '''
        with self.conn:
            self.conn.execute('DELETE FROM expenses WHERE id = ?', (expense_id,))