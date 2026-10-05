def load_users(self, data):
        for user_data in data:
            user = User(user_data['name'])
            user.income = [Transaction(**income) for income in user_data['income']]
            user.expenses = [Transaction(**expense) for expense in user_data['expenses']]
            user.savings_target = user_data['savings_target']
            self.users[user.name] = user