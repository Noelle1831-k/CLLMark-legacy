def get_expenses_by_category(self, category):
        '''
        Retrieves expenses by category.
        :param category: The category to filter by.
        :return: A list of expenses in the specified category.
        '''
        return [expense for expense in self.expenses if expense.category == category]