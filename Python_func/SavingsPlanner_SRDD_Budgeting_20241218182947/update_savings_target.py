def update_savings_target(self, target):
        """
        Updates the savings target.
        """
        self.cursor.execute("DELETE FROM savings_target")
        self.cursor.execute("INSERT INTO savings_target (target) VALUES (?)", (target,))
        self.conn.commit()