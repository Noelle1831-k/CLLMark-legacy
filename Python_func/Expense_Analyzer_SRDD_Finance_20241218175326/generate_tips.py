def generate_tips(self):
        '''
        Generate personalized tips based on the user's spending habits.
        '''
        category_totals = {}
        for expense in self.expenses:
            category = expense.get_category()
            amount = expense.get_amount()
            if category in category_totals:
                category_totals[category] += amount
            else:
                category_totals[category] = amount
        for category, total in category_totals.items():
            if category == 'entertainment' and total > 50:
                print(f"Consider reducing your entertainment expenses. You spent {total} on entertainment.")
            elif category == 'groceries' and total > 100:
                print(f"Consider shopping at discount stores. You spent {total} on groceries.")
            elif category == 'utilities' and total > 150:
                print(f"Consider energy-saving measures. You spent {total} on utilities.")