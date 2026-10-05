def add_expense(self, amount, category, date):
        entry = Entry(amount, category, date)
        self.expense_entries.append(entry)