def save_goal(self, goal):
        '''
        Save a goal entry to the database.
        '''
        with self.conn:
            cursor = self.conn.execute('INSERT INTO goals (description, target_amount) VALUES (?, ?)', (goal.description, goal.target_amount))
            goal.id = cursor.lastrowid