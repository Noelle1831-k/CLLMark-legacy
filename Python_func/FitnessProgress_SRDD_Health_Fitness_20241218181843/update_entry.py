def update_entry(self, entry_id, date, activity, distance, duration):
        # Update an existing entry
        self.db.query_db("UPDATE fitness_data SET date=?, activity=?, distance=?, duration=? WHERE id=?", (date, activity, distance, duration, entry_id))