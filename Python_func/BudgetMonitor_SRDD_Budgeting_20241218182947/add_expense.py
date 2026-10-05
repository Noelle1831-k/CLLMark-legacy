def add_expense(self, amount, category):
        self.user_data['expenses'].append({'amount': amount, 'category': category})
        print(f"Expense added: {format_currency(amount)} in {category}")
        self.check_budget_limits()