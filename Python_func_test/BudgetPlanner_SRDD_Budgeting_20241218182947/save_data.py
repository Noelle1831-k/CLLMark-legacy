def save_data(self, filename):
        '''
        Save the current state of incomes and expenses to a file.
        '''
        data = {
            "incomes": [income.to_dict() for income in self.incomes],
            "expenses": [expense.to_dict() for expense in self.expenses]
        }
        self.file_manager.save_to_file(filename, data)