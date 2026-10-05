def get_expenses_by_category(self):
        categories = {}
        for expense in self.expenses:
            if expense['category'] in categories:
                categories[expense['category']] += expense['amount']
            else:
                categories[expense['category']] = expense['amount']
        return categories