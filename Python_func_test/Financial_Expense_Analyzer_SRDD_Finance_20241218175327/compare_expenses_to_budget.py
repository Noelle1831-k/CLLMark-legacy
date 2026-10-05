def compare_expenses_to_budget(self, expenses):
        report = {}
        for category, amount in expenses.items():
            budget = self.get_budget_for_category(category)
            report[category] = {
                "budget": budget,
                "spent": amount,
                "difference": budget - amount
            }
        return report