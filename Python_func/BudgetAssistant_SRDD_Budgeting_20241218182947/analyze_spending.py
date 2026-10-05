def analyze_spending(self):
        print("Analyzing spending patterns...")
        for category, amount in self.user.expenses.items():
            if category in self.user.budget_goals:
                if amount > self.user.budget_goals[category]:
                    print(f"Overspending detected in {category}: {amount} > {self.user.budget_goals[category]}")
                else:
                    print(f"Spending within budget for {category}: {amount} <= {self.user.budget_goals[category]}")
            else:
                print(f"No budget goal set for {category}. Current spending: {amount}")