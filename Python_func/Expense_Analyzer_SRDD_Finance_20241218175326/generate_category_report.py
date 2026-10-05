def generate_category_report(self):
        '''
        Generate a report summarizing expenses by category.
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
            print(f"Category: {category}, Total: {total}")