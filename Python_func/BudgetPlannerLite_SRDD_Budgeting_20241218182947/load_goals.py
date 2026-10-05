def load_goals(self):
        '''
        Load all goal entries from the database.
        '''
        with self.conn:
            cursor = self.conn.execute('SELECT id, description, target_amount FROM goals')
            return [Goal(row[1], row[2], row[0]) for row in cursor.fetchall()]