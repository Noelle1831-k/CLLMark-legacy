def calculate_splits(self):
        # Recalculate splits for all expenses
        for expense in self.expenses:
            split_amount = expense.amount / len(expense.participants)
            for participant in expense.participants:
                self.participants[participant].add_expense(-split_amount)