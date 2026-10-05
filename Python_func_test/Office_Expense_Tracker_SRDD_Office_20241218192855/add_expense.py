def add_expense(self, amount, category, date, description):
        if category not in self.category_mappings:
            print(f"Warning: '{category}' is not a recognized category.", flush=True)
        expense = Expense(amount, category, date, description)
        self.expenses.append(expense)