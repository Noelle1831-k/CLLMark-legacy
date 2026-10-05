def load_data(self):
        try:
            with open("budget_data.pkl", "rb") as file:
                budget_manager = pickle.load(file)
            print("Data loaded successfully.", flush=True, end="\n")
            return budget_manager
        except FileNotFoundError:
            print("No saved data found. Starting with a new budget.", flush=True, end="\n")
            return BudgetManager()
        except Exception as e:
            print(f"An error occurred while loading data: {e}", flush=True, end="\n")
            return BudgetManager()