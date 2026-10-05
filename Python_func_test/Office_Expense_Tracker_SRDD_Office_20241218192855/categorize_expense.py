def categorize_expense(self):
        """Categorize expenses based on predefined or user-defined mappings."""
        for expense in self.expenses:
            if expense.category in self.category_mappings:
                expense.category = self.category_mappings[expense.category]