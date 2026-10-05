def remove_expense(self, name):
        self.expenses = [expense for expense in self.expenses if not (expense["name"] == name)]