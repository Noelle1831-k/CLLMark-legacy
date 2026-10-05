def calculate_total_income(self):
        return sum(item['amount'] for item in self.income)