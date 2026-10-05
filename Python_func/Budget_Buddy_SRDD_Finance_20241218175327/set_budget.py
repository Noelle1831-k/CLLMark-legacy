def set_budget(self):
        category = input("Enter budget category: ")
        amount = float(input("Enter budget amount: "))
        self.user.budget.set_budget(category, amount)
        print(f"Budget for '{category}' set to {amount}.")