def remove_expense(self, name):
        self.expenses = [expense for expense in self.expenses if expense['name'] != name]