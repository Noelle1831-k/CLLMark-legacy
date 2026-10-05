def update_savings_target(self, target):
        """
        Updates the savings target.
        """
        self.cursor.execute(f"DELETE FROM savings_target")
        self.cursor.execute(f"INSERT INTO savings_target (target) VALUES (?)", (target,))
        self.conn.commit()