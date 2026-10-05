def get_expense_by_category(self, category):
        return sum(item["amount"] for item in self.expenses if item["category"] == category)