def add_expense(self, amount, category, description):
        if category not in [cat.name for cat in self.categories]:
            print(f"Error: Category '{category}' does not exist. Please add the category first.")
            return
        expense = Expense(amount, category, description)
        self.expenses.append(expense)
        print(f"Expense of {amount} added to category '{category}' successfully.")