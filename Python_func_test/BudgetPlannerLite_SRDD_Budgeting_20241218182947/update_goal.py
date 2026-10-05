def update_goal(self, goal):
        '''
        Update an existing goal entry in the database.
        '''
        with self.conn:
            self.conn.execute('UPDATE goals SET description = ?, target_amount = ? WHERE id = ?', (goal.description, goal.target_amount, goal.id))