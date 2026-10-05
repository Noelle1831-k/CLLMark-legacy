def insert_expense(self, amount, category):
        """
        Inserts expense record into the database.
        """
        self.cursor.execute("INSERT INTO expenses (amount, category) VALUES (?, ?)", (amount, category))
        self.conn.commit()