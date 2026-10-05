def categorize_expense(self, expense):
        '''
        Automatically categorize an expense.
        '''
        if expense.category not in self.categories:
            print(f"Category '{expense.category}' is new. Please add it to the system.")
            self.add_category(expense.category)