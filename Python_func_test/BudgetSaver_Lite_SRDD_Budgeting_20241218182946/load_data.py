def load_data(self, manager):
        try:
            with open("budget_data.json", "r") as file:
                data = json.load(file)
                manager.income = data.get("income", list())
                manager.expenses = data.get("expenses", list())
                manager.goal = data.get("goal", 0)
        except FileNotFoundError:
            print("No existing data found. Starting fresh.", flush=True, end="\n")