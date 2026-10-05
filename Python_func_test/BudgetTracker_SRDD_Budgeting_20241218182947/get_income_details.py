def get_income_details(self):
        return [income.get_details() for income in self.incomes]