def get_total_income(self):
        return sum(entry["amount"] for entry in self.income_entries)