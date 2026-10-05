def load_data(self):
        '''
        Load data for categories and expenses from storage.
        '''
        self.data_storage.load_categories_from_file(f'categories.json', self.category_manager)
        self.data_storage.load_expenses_from_file(f'expenses.json', self.expenses)