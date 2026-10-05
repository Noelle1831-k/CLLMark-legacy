def add_expense(self, date, category, amount, description):
        expense_id = utilities.generate_expense_id()
        expense = {
            'id': expense_id,
            'date': date,
            'category': category,
            'amount': amount,
            'description': description
        }
        self.expenses.append(expense)