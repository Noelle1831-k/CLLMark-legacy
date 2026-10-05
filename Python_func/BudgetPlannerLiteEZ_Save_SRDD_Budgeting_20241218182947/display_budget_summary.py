def display_budget_summary(self, budget_data):
        print("Budget Summary:")
        for category, amount in budget_data.items():
            print(f"{category}: ${amount:.2f}")