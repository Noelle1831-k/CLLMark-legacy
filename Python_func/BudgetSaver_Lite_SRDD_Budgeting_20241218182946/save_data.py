def save_data(self, manager):
        data = {
            'income': manager.income,
            'expenses': manager.expenses,
            'goal': manager.goal
        }
        with open('budget_data.json', 'w') as file:
            json.dump(data, file)