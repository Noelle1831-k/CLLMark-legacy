def calculate_total_expenses(self):
        return sum(item['amount'] for item in self.expenses)