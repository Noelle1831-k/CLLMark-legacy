def get_entries(self, username):
        # Retrieve all entries for a user
        return self.db.query_db("SELECT * FROM fitness_data WHERE username=?", (username,))