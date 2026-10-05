def suggest_savings(self, expenses):
        print("\nCost-Saving Suggestions:")
        # Example cost-saving suggestion logic
        for expense in expenses:
            if expense.amount > 150:
                print(f"Consider reducing expenses in {expense.category} for items like {expense.description}.")