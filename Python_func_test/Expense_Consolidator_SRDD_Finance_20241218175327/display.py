def display(self):
        # Simulate displaying the dashboard
        print("Displaying dashboard...")
        for expense in self.expenses:
            print(f"Expense: {expense.amount} in {expense.category}")