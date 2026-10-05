def add_income(self, amount, category):
        self.user_data['income'].append({'amount': amount, 'category': category})
        print(f"Income added: {format_currency(amount)} in {category}")