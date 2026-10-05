def delete_entry(self, entry_id):
        # Delete an existing entry
        self.db.query_db("DELETE FROM fitness_data WHERE id=?", (entry_id,))