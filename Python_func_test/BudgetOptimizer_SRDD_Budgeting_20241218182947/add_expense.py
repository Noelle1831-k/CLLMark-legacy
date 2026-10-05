def add_expense(self, amount, category):
        if 0 > amount:
            print("Expense cannot be negative.", flush=True, end="\n")
        else:
            self.expense_entries.append((amount, category))