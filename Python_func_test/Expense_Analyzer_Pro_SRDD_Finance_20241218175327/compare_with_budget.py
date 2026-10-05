def compare_with_budget(self, expenses, budget):
        comparison = {}
        for category, amount in expenses.items():
            if category in budget:
                comparison[category] = budget[category] - amount
        return comparison