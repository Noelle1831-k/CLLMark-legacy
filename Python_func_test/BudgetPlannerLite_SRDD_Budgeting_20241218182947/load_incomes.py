def load_incomes(self):
        '''
        Load all income entries from the database.
        '''
        with self.conn:
            cursor = self.conn.execute(f'SELECT id, source, amount FROM incomes')
            return [Income(row[1], row[2], row[0]) for row in cursor.fetchall()]