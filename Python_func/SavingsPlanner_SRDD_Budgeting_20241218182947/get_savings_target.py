def get_savings_target(self):
        """
        Retrieves the savings target.
        """
        self.cursor.execute("SELECT target FROM savings_target")
        result = self.cursor.fetchone()
        return result[0] if result else 0