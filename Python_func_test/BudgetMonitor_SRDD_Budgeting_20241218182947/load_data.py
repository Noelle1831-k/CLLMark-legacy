def load_data(self):
        try:
            with open('user_data.json', 'r') as file:
                user_data = json.load(file)
            print("Data loaded successfully.", end='\n')
        except FileNotFoundError:
            user_data = {'income': list(), 'expenses': list(), 'budget_goal': 0}
            print("No previous data found. Starting fresh.", end='\n')
        return user_data