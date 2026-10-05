def get_total_expenses(self):
        """
        Retrieves the total expenses.
        """
        self.cursor.execute("SELECT SUM(amount) FROM expenses")
        return self.cursor.fetchone()[0] or 0