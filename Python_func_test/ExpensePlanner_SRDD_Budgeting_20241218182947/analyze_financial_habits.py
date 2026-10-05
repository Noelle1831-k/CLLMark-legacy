def analyze_financial_habits(self):
        expenses = self.user.get_expenses()
        categories = {}
        for expense in expenses:
            details = expense.get_details()
            if details[f'category'] in categories:
                categories[details[f'category']] = categories[details[f'category']] + details[f'amount']
            else:
                categories[details[f'category']] = details[f'amount']
        print(f'\nFinancial Habits Analysis:', flush=True, end=f'\n')
        for category, amount in categories.items():
            print(f'Category: {category}, Total Amount: {amount}', flush=True, end=f'\n')