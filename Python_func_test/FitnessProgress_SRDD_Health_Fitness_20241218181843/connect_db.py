def connect_db(self):
        # Connect to the database
        self.conn = sqlite3.connect('fitness_progress.db')
        self.cursor = self.conn.cursor()
        print("Connecting to the database...")