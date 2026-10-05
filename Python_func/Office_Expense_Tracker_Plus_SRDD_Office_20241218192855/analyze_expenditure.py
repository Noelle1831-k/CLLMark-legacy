def analyze_expenditure(self):
        '''
        Analyzes expenditure patterns.
        '''
        print("Analyzing expenditure patterns...")
        category_totals = {}
        for expense in self.expenses:
            if expense.category not in category_totals:
                category_totals[expense.category] = 0
            category_totals[expense.category] += expense.amount
        for category, total in category_totals.items():
            budget = self.budgets.get(category)
            if budget:
                percentage = calculate_percentage(total, budget.limit)
                print(f"Category: {category}, Total: {format_currency(total)}, "
                      f"Budget: {format_currency(budget.limit)}, "
                      f"Usage: {percentage:.2f}%")
            else:
                print(f"Category: {category}, Total: {format_currency(total)}, No budget set.")