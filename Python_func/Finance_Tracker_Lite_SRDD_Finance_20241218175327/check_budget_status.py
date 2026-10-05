def check_budget_status(self, expense_entries):
        for entry in expense_entries:
            self.update_budget(entry.amount, entry.category)
        print("\nBudget Status:")
        for category, spent in self.spent.items():
            print(f"Category: {category}, Spent: {spent}, Budget: {self.categories[category]}")
            if spent > self.categories[category]:
                print(f"Warning: Over budget in {category} by {spent - self.categories[category]}")