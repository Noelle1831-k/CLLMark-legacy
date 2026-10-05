def check_budget(self):
        '''
        Checks if any budget has been exceeded.
        '''
        for category, budget in self.budgets.items():
            expenses = [e.amount for e in self.expenses if e.category == category]
            if budget.is_exceeded(expenses):
                print(f"Budget exceeded for {category}!")