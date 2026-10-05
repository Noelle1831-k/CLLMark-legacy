def save_data(self, user):
        '''
        Save user financial data to a file.
        '''
        data = {
            "income": user.income,
            "expenses": user.expenses,
            "budget_goal": user.budget_goal
        }
        with open('user_data.json', 'w') as file:
            json.dump(data, file)