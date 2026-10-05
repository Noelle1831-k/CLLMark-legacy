def get_total_income(self):
        return sum(income.amount for income in self.incomes)