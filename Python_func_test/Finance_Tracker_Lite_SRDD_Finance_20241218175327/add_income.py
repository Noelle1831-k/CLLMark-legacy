def add_income(self, amount, category, date):
        entry = Entry(amount, category, date)
        self.income_entries.append(entry)