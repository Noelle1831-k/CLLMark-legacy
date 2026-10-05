def track_expenses(self):
        for category, amount in self.expenses.items():
            print(f'Category: {category}, Amount: {amount}', end='\n')