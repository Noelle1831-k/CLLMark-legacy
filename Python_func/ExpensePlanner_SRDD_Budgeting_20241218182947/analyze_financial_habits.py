def analyze_financial_habits(self):
        expenses = self.user.get_expenses()
        categories = {}
        for expense in expenses:
            details = expense.get_details()
            if details['category'] in categories:
                categories[details['category']] += details['amount']
            else:
                categories[details['category']] = details['amount']
        print("\nFinancial Habits Analysis:")
        for category, amount in categories.items():
            print(f"Category: {category}, Total Amount: {amount}")