def get_total_expense(self):
        return sum(entry["amount"] for entry in self.expense_entries)