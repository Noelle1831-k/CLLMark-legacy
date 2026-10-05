def calculate_total_expenses(self):
        return sum([cat.budget for cat in self.categories])