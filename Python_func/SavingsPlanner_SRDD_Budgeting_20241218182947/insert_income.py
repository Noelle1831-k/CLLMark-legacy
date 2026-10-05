def insert_income(self, amount, source):
        """
        Inserts income record into the database.
        """
        self.cursor.execute("INSERT INTO income (amount, source) VALUES (?, ?)", (amount, source))
        self.conn.commit()