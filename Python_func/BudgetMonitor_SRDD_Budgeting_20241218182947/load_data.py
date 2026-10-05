def load_data(self):
        try:
            with open('user_data.json', 'r') as file:
                user_data = json.load(file)
            print("Data loaded successfully.")
        except FileNotFoundError:
            user_data = {'income': [], 'expenses': [], 'budget_goal': 0}
            print("No previous data found. Starting fresh.")
        return user_data