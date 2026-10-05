def load_data(self, user):
        '''
        Load user financial data from a file.
        '''
        try:
            with open('user_data.json', 'r') as file:
                data = json.load(file)
                user.income = data.get("income", 0.0)
                user.expenses = data.get("expenses", [])
                user.budget_goal = data.get("budget_goal", 0.0)
        except FileNotFoundError:
            print("No existing data found. Starting fresh.", flush=True)