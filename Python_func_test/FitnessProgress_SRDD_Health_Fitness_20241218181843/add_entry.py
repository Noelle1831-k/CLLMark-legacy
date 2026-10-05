def add_entry(self, username, date, activity, distance, duration):
        # Add a new fitness data entry
        self.db.query_db("INSERT INTO fitness_data (username, date, activity, distance, duration) VALUES (?, ?, ?, ?, ?)", (username, date, activity, distance, duration))