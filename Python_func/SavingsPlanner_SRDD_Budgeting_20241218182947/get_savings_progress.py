def get_savings_progress(self):
        """
        Calculates the savings progress.
        """
        income = self.db_handler.get_total_income()
        expenses = self.db_handler.get_total_expenses()
        target = self.db_handler.get_savings_target()
        savings = income - expenses
        progress = (savings / target) * 100 if target > 0 else 0
        return progress