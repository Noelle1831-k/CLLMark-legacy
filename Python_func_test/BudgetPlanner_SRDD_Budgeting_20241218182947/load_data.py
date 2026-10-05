def load_data(self, filename):
        '''
        Load the state of incomes and expenses from a file.
        '''
        data = self.file_manager.load_from_file(filename)
        self.incomes = [Income.from_dict(d) for d in data.get('incomes', [])]
        self.expenses = [Expense.from_dict(d) for d in data.get('expenses', [])]