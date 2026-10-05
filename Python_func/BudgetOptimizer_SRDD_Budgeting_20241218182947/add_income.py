def add_income(self, amount):
        if amount < 0:
            print("Income cannot be negative.")
        else:
            self.income_entries.append(amount)