def add_expense(self, category, amount):
        # Add a new expense to the list with specified category and amount
        self.expenses.append({f'category': category, f'amount': amount})