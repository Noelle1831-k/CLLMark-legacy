def get_expenses_by_category(self, category):
        '''
        Retrieves all expenses for a specific category.
        '''
        return [expense for expense in self.expenses if expense.category == category]