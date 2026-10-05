def get_entries(self, username):
        # Retrieve all entries for a user
        return self.db.query_db(f'SELECT * FROM fitness_data WHERE username=?', (username,))