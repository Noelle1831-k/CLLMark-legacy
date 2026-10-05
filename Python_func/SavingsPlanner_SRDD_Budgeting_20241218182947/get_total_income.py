def get_total_income(self):
        """
        Retrieves the total income.
        """
        self.cursor.execute("SELECT SUM(amount) FROM income")
        return self.cursor.fetchone()[0] or 0